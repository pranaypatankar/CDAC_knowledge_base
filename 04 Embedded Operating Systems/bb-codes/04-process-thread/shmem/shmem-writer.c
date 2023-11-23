#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

#include "shmem.h"

void report_and_exit (const char *msg)
{
	perror (msg);
	exit (EXIT_FAILURE);
}

int main ()
{
	char data[] = "Hello this is the writer\n";

	int fd = shm_open (SHMEM_NAME,	/* name of backing file */
		     O_RDWR | O_CREAT,	/* read/write, create if needed */
		     0644);
  	if (fd < 0)
    		report_and_exit ("Can't open shared mem segment");
	fprintf(stderr, "- Opened memory segment: %s\n", SHMEM_NAME);

 	ftruncate (fd, SHMEM_SZ);	/* set the size */
	fprintf(stderr, "- Segment size set to %d\n", SHMEM_SZ);

  	caddr_t memptr = mmap (NULL,	/* let system pick where to put segment */
			 SHMEM_SZ,	/* how many bytes */
			 PROT_READ | PROT_WRITE,	/* access protections */
			 MAP_SHARED,	/* mapping visible to other processes */
			 fd,		/* file descriptor */
			 0);		/* offset: start at 1st byte */

  	if ((caddr_t) - 1 == memptr)
    		report_and_exit ("Can't get mem segment");

  	fprintf (stderr, "-- Shared mem address: %p [0..%d]\n", memptr, SHMEM_SZ - 1);
  	fprintf (stderr, "-- Backing file: /dev/shm/%s\n", SHMEM_NAME);

	  /* semaphore code to lock the shared mem */
  	sem_t *semptr = sem_open (SHMEM_SEMA,	/* name */
			    	  O_CREAT,	/* create the semaphore */
			    	  0644,		/* protection perms */
			    	  0);		/* initial value */

  	if (semptr == (void *) -1)
    		report_and_exit ("sem_open error");

	fprintf(stderr, "- Got the semaphore: %s\n", SHMEM_SEMA);
  	strcpy (memptr, data);	/* copy some ASCII bytes to the segment */
	int sleep_time = 10;			/* take some time */
	while (sleep_time)
	{
		sleep(1);
		fprintf(stderr, "Writer sleep: writing data %d\n", sleep_time);
		sleep_time--;
	}
	
  	/* increment the semaphore so that memreader can read */
  	if (sem_post (semptr) < 0)
    		report_and_exit ("sem_post error");

	fprintf(stderr, "- Posted the semaphore: %s\n", SHMEM_SEMA);

  	sleep_time = 10;			/* give reader a chance */
	while (sleep_time)
	{
		sleep(1);
		fprintf(stderr, "Writer sleep: waiting for read %d\n", sleep_time);
		sleep_time--;
	}

  	/* clean up */
	fprintf(stderr, "Cleaning up\n");

  	munmap (memptr, SHMEM_SZ);	/* unmap the storage */
	fprintf(stderr, "- Mem segment: %s unmapped\n", SHMEM_NAME);
	close (fd);

  	sem_close (semptr);
	sem_unlink (SHMEM_SEMA);
	fprintf(stderr, "- Semaphore: %s unlinked\n", SHMEM_SEMA);
  	
	shm_unlink (SHMEM_NAME);	/* unlink from the backing file */
  	fprintf(stderr, "- Backing file %s unlinked\n", SHMEM_NAME);

	return EXIT_SUCCESS;

}
