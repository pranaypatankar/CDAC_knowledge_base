#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int i = 15;

void ctrlc_handler(int sig)
{
	fprintf(stderr, "Caught a CTRL-C: reducing i ");
	i = (i>5) ? (i-5):0 ;
	if (i)
		fprintf(stderr, "by 5!\n");
	else
		fprintf(stderr, "to 0!\n");

	return;
}

int main()
{
	struct sigaction sa;

	sa.sa_handler = ctrlc_handler;	// define a handler
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask); 	// empty the mask now

	int ret = sigaction(SIGINT, &sa, NULL);
	if (-1 == ret)
	{
		perror("Error in sigaction");
		exit (EXIT_FAILURE);
	}

	fprintf(stderr, "Starting %s with i=%d\n", __func__, i);
	while(i>0)
	{
		sleep(1);
		fprintf(stderr, "\tsleeping, i=[%d]\n", i);
		i--;
	}

	fprintf(stderr, "%s is done!\n", __func__);

	exit (EXIT_SUCCESS);
}


