#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	FILE *fp;
	char str_w[] = "Hello world!";
	char str_r[100] = {0};
	int str_length = strlen(str_w);

	char fname_txt[] = "file.txt";
	char fname_bin[] = "file.bin";

	// ascii write and read
	fprintf(stdout, "****** Ascii read-write ******\n");	
	fprintf(stdout, "String to write: %s\n", str_w);

	fp = fopen(fname_txt, "w");
	if (fp==NULL)
	{
		fprintf(stdout, "Cannot open %s for writing!\n", fname_txt);
		return EXIT_FAILURE;
	}
	fprintf(fp, "%s\n", str_w);
	fclose(fp);
	fprintf(stdout, "Wrote \"%s\" to %s\n", str_w, fname_txt);

	fp = fopen(fname_txt, "r");
	if (fp==NULL)
	{
		fprintf(stdout, "Cannot open %s for reading!\n", fname_txt);
		return EXIT_FAILURE;
	}
	char *str_ptr = str_r;
	if ( fgets(str_ptr, str_length, fp)!= NULL )
		printf("String read is: %s\n", str_r);	
	fclose(fp);

	fprintf(stdout, "\n\n");

	// binary write and read
	fprintf(stdout, "****** Binary read-write ******\n");	
	int nums = 100;
	fp = fopen(fname_bin, "w");
	if (fp==NULL)
	{
		fprintf(stdout, "Cannot open %s for writing!\n", fname_bin);
		return EXIT_FAILURE;
	}
	for (int i=0;i<nums;i++)
		fwrite((const void *)&i, sizeof(int), 1, fp);
	fclose(fp);
	fprintf(stdout, "Wrote %d ints to %s\n", nums, fname_bin);

	fp = fopen(fname_bin, "r");
	if (fp==NULL)
	{
		fprintf(stdout, "Cannot open %s for reading!\n", fname_bin);
		return EXIT_FAILURE;
	}
	fprintf(stdout, "Reading %d ints from %s...\n", nums, fname_bin);
	for (int i=0;i<nums;i++)
	{
		int t;
		fread((void *)&t, sizeof(int), 1, fp);
		printf("%d ", t);
	}
	fprintf(stdout, "\n");
	fclose(fp);

	return EXIT_SUCCESS;
}
