#include <stdio.h>
#include <sys/wait.h>		/* wait */
#include <stdlib.h>		/* exit functions */
#include <unistd.h>		/* read, write, pipe, _exit */
#include <string.h>

#define ReadEnd 0
#define WriteEnd 1

void report_and_exit (const char *msg)
{
	perror (msg);
	exit (EXIT_FAILURE);
}

int main ()
{
	int pipeFDs[2];			/* two file descriptors */
	char buf;			/* 1-byte buffer */
  	const char *msg = "This is the message for the pipe!\n";
  
	if (pipe (pipeFDs) < 0)
    		report_and_exit ("pipe crreation failed");
	else
		fprintf(stderr, "******** %s:: Pipe created at %p\n", __func__, pipeFDs);

  	pid_t cpid = fork ();
	if (cpid < 0)
    		report_and_exit ("fork failure");
  
	if (0 == cpid)
    	{	/*** child ***//* child process */
		fprintf(stderr, "\tCHILD:: I am the child with PID[%d]\n", getpid());

		fprintf(stderr, "\tCHILD:: I am a reader, closing my WriteEnd\n");
      		close (pipeFDs[WriteEnd]);	/* child reads, doesn't write */
      		
		fprintf(stderr, "\tCHILD:: Getting data from the pipe %p\n\t\tRecvd message --> ", pipeFDs);
		while (read (pipeFDs[ReadEnd], &buf, 1) > 0)		/* read until end of byte stream */
			write (STDOUT_FILENO, &buf, sizeof (buf));	/* echo to the standard output */
      
		fprintf(stderr, "\tCHILD:: Read done, closing my ReadEnd\n");
		
		close (pipeFDs[ReadEnd]);	/* close the ReadEnd: all done */
      
		_exit (0);			/* exit and notify parent at once */
	}
  	else
    	{  	/*** parent ***/
		fprintf(stderr, "PARENT:: I am the parent with PID[%d]\n", getpid());
		
		fprintf(stderr, "PARENT:: I am a writer, closing my ReadEnd\n");
      		close (pipeFDs[ReadEnd]);	/* parent writes, doesn't read */
     
	        fprintf(stderr, "PARENT:: Sending message to the pipe %p\n", pipeFDs);
		fprintf(stderr, "\tSent message --> %s", msg); 	
		write (pipeFDs[WriteEnd], msg, strlen (msg));	/* write the bytes to the pipe */

		fprintf(stderr, "PARENT:: Write done, closing my WriteEnd\n");
      		close (pipeFDs[WriteEnd]);	/* done writing: generate eof */
      	
		fprintf(stderr, "PARENT:: Waiting for my child...\n");
		wait (NULL);			/* wait for child to exit */
	
		fprintf(stderr, "PARENT:: My child terminated! I am also done!\n");	
		exit (EXIT_SUCCESS);		/* exit normally */
	}
  	
	return EXIT_SUCCESS;
}
