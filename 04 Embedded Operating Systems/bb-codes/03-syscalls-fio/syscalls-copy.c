#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <errno.h>

#define debug_printf 

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		printf("Usage: %s <a.bin> <b.bin> <buffer_size>\n", argv[0]);
                printf("a.bin is the file to copy from\n");
                printf("b.bin is the file to copy to\n");
		printf("buffer_size is the size of buffer to use\n");
                exit (EXIT_FAILURE);
	}
	
	char *fname = argv[1];
	char *fname_copy = argv[2];
	int buf_sz = atoi(argv[3]);
        char *buf = (char *)malloc(buf_sz * sizeof(char));

	int fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		char err_str[100] = {0};
		sprintf(err_str, "Cannot open %s for read", fname);
		perror(err_str);
		exit (EXIT_FAILURE);
	}
	off_t file_size = lseek(fd, 0, SEEK_END);
	printf("Filesize of %s is %lld bytes\n", fname, (long long) file_size);

	int flags = O_CREAT | O_RDWR | O_TRUNC;
       	int mode = S_IRUSR | S_IWUSR | S_IRGRP;
	int fd_out = open(fname_copy, flags, mode);
	if (fd_out == -1)
	{
		char err_str[100] = {0};
		sprintf(err_str, "Cannot open %s for write", fname_copy);
		perror(err_str);
		exit (EXIT_FAILURE);
	}

	off_t begin = lseek(fd, 0, SEEK_SET); // rewind fd ptr
	printf("begin is %lld\n", (long long)begin);

	ssize_t nread;
	while( (nread=read(fd, (void *)buf, buf_sz)) > 0 )
	{
		debug_printf("Read %zd bytes from %s\n", nread, fname);
		ssize_t nwrite = write(fd_out, buf, nread);
		debug_printf("Wrote %zd bytes to %s\n", nwrite, fname_copy);
		if (nwrite != nread)
		{
			char err_str[100] = {0};
			sprintf(err_str, "Partial write to %s occurred", fname_copy);
			perror(err_str);
			exit (EXIT_FAILURE);
		}
	}
	if (nread == -1)
	{
		char err_str[100] = {0};
		sprintf(err_str, "Read error on %s", fname);
		perror(err_str);
		exit (EXIT_FAILURE);
	}

	free(buf);
	if (close(fd) == -1)
	{
		char err_str[100] = {0};
		sprintf(err_str, "Close error on %s", fname);
		perror(err_str);
		exit (EXIT_FAILURE);
	}
	if (close(fd_out) == -1)
	{
		char err_str[100] = {0};
		sprintf(err_str, "Close error on %s", fname_copy);
		perror(err_str);
		exit (EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
