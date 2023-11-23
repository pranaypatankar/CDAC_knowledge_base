#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

unsigned is_prime (unsigned n)
{
	if (n <= 3)
    		return n > 1;
  	if (0 == (n % 2) || 0 == (n % 3))
    		return 0;
  
	unsigned i;
  	for (i = 5; (i * i) <= n; i += 6)
    		if (0 == (n % i) || 0 == (n % (i + 2)))
      			return 0;

  	return 1;			/* found a prime! */
}

int main()
{
	const char *file = "./myfifo-001";
  
	int fd = open(file, O_RDONLY);
  	if (fd < 0)
	{
		char error_str[100] = {0};
		sprintf(error_str, "Cannot open %s", file);
		perror(error_str);
    		exit(EXIT_FAILURE);
	}

	unsigned total = 0, primes_count = 0;
  	while (1)
    	{
      		int number;
      		ssize_t count = read (fd, &number, sizeof(int)); /* read 1 int */
      		if (0 == count)
		{
			printf("FIFO:%s empty - ending read\n", file);
			break;			/* end of stream */
		}
      		else if (count == sizeof (int))
		{				/* got an integer */
			printf("Read integer%d[%d] - running is_prime()\n", total, number);
	  		total++;
	  		if (is_prime(number))
	    			primes_count++;
		}
    	}
  
	close(fd);			/* close pipe from read end */
  	unlink(file);			/* unlink from the underlying file */
  
	printf("Received ints: %u, primes: %u\n", total, primes_count);
  
	exit(EXIT_FAILURE);
}
