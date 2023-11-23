#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int supports_full_hd (const char *const monitor);

int main ()
{
  int fp = open ("monitor.json",O_RDONLY);
  if (fp == -1)
    {
      printf ("Error: Unable to open the file.\n");
      return 1;
    }

   lseek (fp, 0, SEEK_END);
   long size = ftell(fp);

  char *buffer = (char *) malloc (1024 * sizeof (char));
  if (buffer == NULL)
    {
      printf ("Error: Unable to allocate buffer.\n");
      return 1;
    }

  lseek (fp, 0, SEEK_SET);
  read (fp,buffer,strlen(buffer));
  close (fp);

  int result = supports_full_hd ((const char *const)buffer);
  fprintf(stdout,"HD supported: %s\n", (result==1)?"Yes":"No");

  free (buffer);
  return 0;
}

/* return 1 if the monitor supports full hd, 0 otherwise */
int supports_full_hd (const char *const monitor)
{
  const cJSON *resolution = NULL;
  const cJSON *resolutions = NULL;
  const cJSON *name = NULL;
  int status = 0;
  cJSON *monitor_json = cJSON_Parse (monitor);
  if (monitor_json == NULL)
    {
      const char *error_ptr = cJSON_GetErrorPtr ();
      if (error_ptr != NULL)
	{
	  fprintf (stderr, "Error before: %s\n", error_ptr);
	}
      status = 0;
      goto end;
    }

  name = cJSON_GetObjectItemCaseSensitive (monitor_json, "name");
  if (cJSON_IsString (name) && (name->valuestring != NULL))
    {
      printf ("Checking monitor \"%s\"\n", name->valuestring);
    }

  resolutions =
    cJSON_GetObjectItemCaseSensitive (monitor_json, "resolutions");
  cJSON_ArrayForEach (resolution, resolutions)
  {
    cJSON *width = cJSON_GetObjectItemCaseSensitive (resolution,
						     "width");
    cJSON *height = cJSON_GetObjectItemCaseSensitive (resolution,
						      "height");
    if (!cJSON_IsNumber (width) || !cJSON_IsNumber (height))
      {
	status = 0;
	goto end;
      }

    if ((width->valuedouble == 1920) && (height->valuedouble == 1080))
      {
	status = 1;
	goto end;
      }
  }

end:
  cJSON_Delete (monitor_json);
  return status;
}
