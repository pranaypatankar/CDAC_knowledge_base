#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void report_and_exit (const char *msg)
{
	perror (msg);
	exit (EXIT_FAILURE);			/* EXIT_FAILURE */
}

int main ()
{
	char fname[] = "file.dat";

  	struct flock lock;
  	lock.l_type = F_WRLCK;		/* read/write (exclusive) lock */
  	lock.l_whence = SEEK_SET;	/* base for seek offsets */
  	lock.l_start = 0;		/* 1st byte in file */
  	lock.l_len = 0;			/* 0 here means 'until EOF' */
  	lock.l_pid = getpid ();		/* process id */

  	int fd;				/* file descriptor */
  	if ((fd = open (fname, O_RDONLY)) < 0)	/* -1 signals an error */
    		report_and_exit ("open to read failed");

  	/* If the file is write-locked, we wait */
  	fcntl (fd, F_GETLK, &lock);	/* sets lock.l_type to F_UNLCK if no write lock */
	while(lock.l_type != F_UNLCK)
	{
  		fprintf(stderr, "Waiting for file write unlock...\n");
		sleep(1);
  		fcntl (fd, F_GETLK, &lock);	/* sets lock.l_type to F_UNLCK if no write lock */
	}
  
	lock.l_type = F_RDLCK;	/* prevents any writing during the reading */
  	if (fcntl (fd, F_SETLK, &lock) < 0)
    		report_and_exit ("can't get a read-only lock...");
 
        fprintf(stderr, "Got read lock on file: %s\n", fname);
	/* Read the bytes (they happen to be ASCII codes) one at a time. */
  	int c;					/* buffer for read bytes */
  	while (read (fd, &c, 1) > 0)		/* 0 signals EOF */
    		write (STDOUT_FILENO, &c, 1);	/* write one byte to the standard output */
 
       	/* Release the lock explicitly. */
  	lock.l_type = F_UNLCK;
  	if (fcntl (fd, F_SETLK, &lock) < 0)
    		report_and_exit ("explicit unlocking failed");
  
	close (fd);
  
	return EXIT_SUCCESS;

}
