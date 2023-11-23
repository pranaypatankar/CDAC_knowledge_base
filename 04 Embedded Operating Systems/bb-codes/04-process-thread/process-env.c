#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main()
{
	for (char **ep = environ; *ep != NULL; ep++)
		puts(*ep);

	printf("\n\n");
	// Getting an environment variable
	printf("USER = %s\n", getenv("USER"));
	printf("HOME = %s\n", getenv("HOME"));
	printf("SHELL = %s\n", getenv("SHELL"));
	printf("PATH = %s\n", getenv("PATH"));

	return 0;
}
