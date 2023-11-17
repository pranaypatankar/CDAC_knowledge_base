#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void report_and_exit (const char *msg)
{
	perror (msg);
	exit (EXIT_FAILURE);			/* EXIT_FAILURE */
}

int main ()
{
	char fname[] = "file.dat";

  	struct flock lock;
  	lock.l_type = F_WRLCK;		/* read/write (exclusive versus shared) lock */
  	lock.l_whence = SEEK_SET;	/* base for seek offsets */
  	lock.l_start = 0;		/* 1st byte in file */
  	lock.l_len = 0;			/* 0 here means 'until EOF' */
  	lock.l_pid = getpid ();		/* process id */

  	int fd;				/* file descriptor */
  	if ((fd = open (fname, O_RDWR | O_CREAT, 0666)) < 0)	/* -1 signals an error */
    		report_and_exit ("open failed...");

	fprintf(stderr, "Trying to get a write lock on file: %s...", fname);
  	if (fcntl (fd, F_SETLKW, &lock) < 0)
    		report_and_exit ("Failed to get write lock");
  	else
    	{
		fprintf(stderr, "got the lock\n");
		int sleep_time = 5;
		while(sleep_time)
		{
			printf("Writing...%d\n", sleep_time);
			sleep(1);
			sleep_time--;
		}
		char output[100] = {0};
		sprintf(output, "PID[%d]: This is the stuff I want to write!\n", lock.l_pid);
      		write (fd, output, strlen(output));
      		fprintf (stderr, "Writer process %d has written to file: %s...\n", lock.l_pid, fname);
    	}

  	/* Now release the lock explicitly. */
  	lock.l_type = F_UNLCK;
  	if (fcntl (fd, F_SETLK, &lock) < 0)
    		report_and_exit ("Write unlocking failed");
  	
	close (fd);			/* close the file: would unlock if needed */
  	
	return EXIT_SUCCESS;		/* terminating the process would unlock as well */

}
