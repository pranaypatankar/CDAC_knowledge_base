#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

#define BUF_SZ	(1024)

#define debug_printf 

int main(int argc, char *argv[])
{
	FILE *fp, *fp_out;

	if (argc < 3)
	{
		printf("Usage: %s <a.bin> <b.bin>\n", argv[0]);
		printf("a.bin is the file to copy from\n");
		printf("b.bin is the file to copy to\n");
		exit (EXIT_FAILURE);
	}

	char *fname = argv[1];
	char *fname_copy = argv[2];
	char buf[BUF_SZ];

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

	int begin = fseek(fp, 0, SEEK_SET); // rewind fp ptr
	printf("begin is %d\n", begin);

	size_t nread;
	while( (nread=fread((void *)buf, 1, BUF_SZ, fp)) > 0 )
	{
		debug_printf("Read %d bytes from %s\n", nread, fname);
		ssize_t nwrite = fwrite((const void *)buf, 1, nread, fp_out);
		debug_printf("Wrote %d bytes to %s\n", nwrite, fname_copy);
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
