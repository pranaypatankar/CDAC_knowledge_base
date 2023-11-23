#include <stdio.h> // for printf, etc.
#include <string.h> // for strerror
#include <errno.h> // for perror - not used here
#include <stdint.h> //for uint32_t

int main()
{
	uint32_t i;
	
	for (i=0;i<133;i++)
	{
		printf("%d: %s\n", i, strerror(i));
	}
	
	// %d int, %ld is long int, %lld is long long int
	
	return 0;
}
