#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxLoops 	10		
#define MaxSleep	5

int main ()
{
	const char *fifoname = "./myfifo-001";
  	mkfifo(fifoname, 0666);	/* read/write for user/group/others */
  
	int fd = open(fifoname, O_CREAT | O_WRONLY);	/* open as write-only */
  	if (fd < 0)
    		exit(EXIT_FAILURE);
  
	int i;
  	for (i = 0; i < MaxLoops; i++)
    	{
		printf("Loop[%d]: ", i);
	    	int to_send = rand();	/* get a random integer */
		printf("Sending integer[%d]\n", to_send);
	  	write(fd, (void *)&to_send, sizeof(to_send));
		
		int to_sleep = (rand() % MaxSleep) + 1;
	        printf("\tSleeping for %d secs...\n", to_sleep);	
      		sleep(to_sleep);
    	}

  	close(fd);			/* close pipe: generates an end-of-stream marker */
 	unlink(fifoname);		/* unlink from the implementing file */
  
	printf("%d ints sent to the pipe.\n", MaxLoops);
  
	exit(EXIT_FAILURE);
}
