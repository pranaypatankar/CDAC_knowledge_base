#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void sigchld_handler(int sig)
{
	printf("PARENT:: %s: My child was killed :(\n", __func__);
	return;
}

int main(void)
{
	int pid;
	int status;

	struct sigaction sa;

	sa.sa_handler = sigchld_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	int ret = sigaction(SIGCHLD, &sa, NULL);
	if (-1 == ret)
	{
		perror("sigaction error!");
		exit (EXIT_FAILURE);
	}

	pid = fork();
	if (pid == 0) 
	{	// child process code
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
	{	// parent process code
		pid_t child_pid = pid;
		printf("PARENT:: I am the parent, PID %d\n", getpid());
		printf("PARENT:: Waiting for my child...\n");
		int parent_sleep = 5;
		while(parent_sleep)
		{
			printf("PARENT:: sleeping %d\n", parent_sleep);
			parent_sleep--;
			sleep(1);
		}
		printf("PARENT:: Sending SIGINT to child[%d]\n", child_pid);
		kill(child_pid, SIGINT);

		wait(&status);
		if (WIFSIGNALED(status))
			psignal(WTERMSIG(status), "PARENT:: Child terminated due to");
		else
			printf("PARENT:: Child terminated, status %d\n", WEXITSTATUS(status));
	} else
		perror("fork:");
	
	exit (EXIT_SUCCESS);
}
