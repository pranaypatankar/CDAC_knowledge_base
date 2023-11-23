#include <stdio.h>
#include <cjson/cJSON.h>

char *create_monitor_with_helpers (void);

int
main ()
{
  char *json_str = create_monitor_with_helpers ();

  FILE *fp = fopen ("monitor.json", "w");
  printf ("%s\n", json_str);
  fputs (json_str, fp);
  fclose (fp);

  // free the JSON string and cJSON object
  cJSON_free (json_str);
  return 0;
}


//NOTE: Returns a heap allocated string, you are required to free it after use.
char *
create_monitor_with_helpers (void)
{
  const unsigned int resolution_numbers[3][2] = {
    {1280, 720},
    {1920, 1080},
    {3840, 2160}
  };
  char *string = NULL;
  cJSON *resolutions = NULL;
  size_t index = 0;

  cJSON *monitor = cJSON_CreateObject ();

  if (cJSON_AddStringToObject (monitor, "name", "Awesome 4K") == NULL)
    {
      goto end;
    }

  resolutions = cJSON_AddArrayToObject (monitor, "resolutions");
  if (resolutions == NULL)
    {
      goto end;
    }

  for (index = 0; index < (sizeof (resolution_numbers) / (2 * sizeof (int)));
       ++index)
    {
      cJSON *resolution = cJSON_CreateObject ();

      if (cJSON_AddNumberToObject
	  (resolution, "width", resolution_numbers[index][0]) == NULL)
	{
	  goto end;
	}

      if (cJSON_AddNumberToObject
	  (resolution, "height", resolution_numbers[index][1]) == NULL)
	{
	  goto end;
	}

      cJSON_AddItemToArray (resolutions, resolution);
    }

  string = cJSON_Print (monitor);
  if (string == NULL)
    {
      fprintf (stderr, "Failed to print monitor.\n");
    }

end:
  cJSON_Delete (monitor);
  return string;
}
