#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int pid;
	int status;
	pid = fork();
	if (pid == 0) 
	{
		int i=10, retval=42;
		printf("\tCHILD:: I am the child, PID %d\n", getpid());
		while(i)
		{
			printf("\tCHILD:: I am the child, sleeping (%d)!\n", i);
			sleep(1);
			i--;
		}
		printf("\tCHILD:: I am the child, returning %d\n", retval);
		exit(retval);
	} else if (pid > 0) 
	{
		printf("PARENT:: I am the parent, PID %d\n", getpid());
		printf("PARENT:: Waiting for my child...\n");
		wait(&status);
		printf("PARENT:: Child terminated, status %d\n", WEXITSTATUS(status));
	} else
		perror("fork:");
	
	return 0;
}
