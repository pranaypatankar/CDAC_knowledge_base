#include <stdio.h>
#include <string.h>

#define _GNU_SOURCE // for NSIG
#include <signal.h>

int main()
{
	for (int i=1;i<NSIG;i++)
		printf("%d: %s\n", i, strsignal(i));

	return 0;
}

