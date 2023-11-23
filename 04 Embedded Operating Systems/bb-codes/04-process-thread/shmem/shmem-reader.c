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
	int fd = shm_open (SHMEM_NAME, O_RDWR, 0644);	/* empty to begin */
  	if (fd < 0)
    		report_and_exit ("Can't get fd for mem-segment");

  	/* get a pointer to memory */
  	caddr_t memptr = mmap (NULL,	/* let system pick where to put segment */
			 SHMEM_SZ,	/* how many bytes */
			 PROT_READ | PROT_WRITE,	/* access protections */
			 MAP_SHARED,	/* mapping visible to other processes */
			 fd,		/* file descriptor */
			 0);		/* offset: start at 1st byte */

  	if ((caddr_t) - 1 == memptr)
    		report_and_exit ("Can't access mem-segment");
	fprintf(stderr, "- Got access to memory segment: %s\n", SHMEM_NAME);

  	/* open existing semaphore for mutual exclusion */
  	sem_t *semptr = sem_open (SHMEM_SEMA,	/* name */
			    	  O_RDWR,	/* create the semaphore */
			    	  0644,		/* protection perms */
			          0);		/* initial value */

  	if (semptr == (void *) -1)
    		report_and_exit ("sem_open");

	fprintf(stderr, "Trying to get semaphore: %s...", SHMEM_SEMA);
  	/* use semaphore as a mutex (lock) by waiting for writer to increment it */
  	if (!sem_wait (semptr))
    	{				/* wait until semaphore != 0 */
		fprintf(stderr, "Got it\n");
      		int i;
      		for (i = 0; i < SHMEM_SZ; i++)
			write (STDOUT_FILENO, memptr + i, 1);	/* one byte at a time */
      		sem_post (semptr);
    	}

  	/* cleanup */
  	munmap (memptr, SHMEM_SZ);
	fprintf(stderr, "- Mem segment: %s unmapped\n", SHMEM_NAME);
  	close (fd);

  	sem_close (semptr);

  	return EXIT_SUCCESS;

}
