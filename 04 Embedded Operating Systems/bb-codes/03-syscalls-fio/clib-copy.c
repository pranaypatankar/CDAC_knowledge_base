#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

#define debug_printf 

int main(int argc, char *argv[])
{
	FILE *fp, *fp_out;

	if (argc < 4)
	{
		printf("Usage: %s <a.bin> <b.bin> <buffer_size>\n", argv[0]);
		printf("a.bin is the file to copy from\n");
		printf("b.bin is the file to copy to\n");
		printf("buffer_size is the size of the buffer to use\n");
		exit (EXIT_FAILURE);
	}

	char *fname = argv[1];
	char *fname_copy = argv[2];
	int buf_sz = atoi(argv[3]);
	char *buf = (char *)malloc(buf_sz * sizeof(char));

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		char err_str[100] = {0};
		sprintf(err_str, "Cannot open %s for read", fname);
		perror(err_str);
		exit (EXIT_FAILURE);
	}
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	printf("Filesize of %s is %ld bytes\n", fname, file_size);

	fp_out = fopen(fname_copy, "w");
	if (fp_out == NULL)
	{
		char err_str[100] = {0};
		sprintf(err_str, "Cannot open %s for write", fname_copy);
		perror(err_str);
		exit (EXIT_FAILURE);
	}

	setvbuf(fp_out, NULL, _IONBF, 0);

	int begin = fseek(fp, 0, SEEK_SET); // rewind fp ptr
	printf("begin is %d\n", begin);

	long to_read = file_size;
	while( to_read > 0 )
	{
#define MIN(a,b)	((a)<(b)?(a):(b))
		int bytes_to_read = MIN(to_read, buf_sz);
		size_t nread=fread((void *)buf, 1, bytes_to_read, fp);
		if (nread != bytes_to_read)
		{
			fprintf(stderr, "Failure reading from %s", fname);
			exit (EXIT_FAILURE);
		}

		debug_printf("Read %lu bytes from %s\n", nread, fname);
		to_read -= buf_sz;

		ssize_t nwrite = fwrite((const void *)buf, 1, nread, fp_out);
		debug_printf("Wrote %ld bytes to %s\n", nwrite, fname_copy);
		if (nwrite != nread)
		{
			char err_str[100] = {0};
			sprintf(err_str, "Partial write to %s occurred", fname_copy);
			perror(err_str);
			exit (EXIT_FAILURE);
		}
	}

	free(buf);
	if (fclose(fp) != 0)
	{
		char err_str[100] = {0};
		sprintf(err_str, "Close error on %s", fname);
		perror(err_str);
		exit (EXIT_FAILURE);
	}
	if (fclose(fp_out) != 0)
	{
		char err_str[100] = {0};
		sprintf(err_str, "Close error on %s", fname_copy);
		perror(err_str);
		exit (EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
