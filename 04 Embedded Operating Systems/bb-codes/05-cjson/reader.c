#include <stdio.h>
#include <cjson/cJSON.h>
#include <stdlib.h>

int
supports_full_hd (const char *const monitor)
{
  const cJSON *batter = NULL;
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

  name = cJSON_GetObjectItemCaseSensitive (monitor_json, "batters");
  if (cJSON_IsString (name) && (name->valuestring != NULL))
    {
      printf ("Checking monitor \"%s\"\n", name->valuestring);
    }

  resolutions =cJSON_GetObjectItemCaseSensitive (monitor_json, "batter");
  cJSON_ArrayForEach (batter, resolutions)
  {
  	int num_batters = cJSON_GetArraySize (batter);
  	for (int i = 0; i < num_batters; i++)
  {
    cJSON *id = cJSON_GetObjectItemCaseSensitive (batter,
						     "id");
    cJSON *type = cJSON_GetObjectItemCaseSensitive (batter,
						      "type");

    if ((id->valuestring == "1001"))
      {
		printf("Regular(1001)\n");
      }
	else if ((id->valuestring == "1002"))
	  {
		printf("Choclate(1002)\n");
	  }
	else if ((id->valuestring == "1003"))
	  {
		printf("Blueberry(1003)\n");
	  }
	else if ((id->valuestring == "1004"))
	  {
		printf("Devil's food(1004)\n");
	  }
	  else {
	  	printf("Error\n");
	  }
	}
  }
end :
  cJSON_Delete (monitor_json);
  return status;
}

int
main ()
{
  FILE *fp = fopen ("sample.json", "r");
  if (fp == NULL)
    {
      printf ("Error: Unable to open the file.\n");
      return 1;
    }

  fseek (fp, 0, SEEK_END);
  long size = ftell(fp);

  char *buffer = (char *) malloc (size * sizeof (char));
  if (buffer == NULL)
    {
      printf ("Error: Unable to allocate buffer.\n");
      return 1;
    }

  fseek (fp, 0, SEEK_SET);
  fread (buffer, 1, size, fp);
  fclose (fp);

  int result = supports_full_hd ((const char *const)buffer);
  printf("HD supported: %s\n", (result==1)?"Yes":"No");

  free (buffer);
  return 0;
}

