#include <stdio.h>
#include <cjson/cJSON.h>

int
main ()
{
  // open the file 
  FILE *fp = fopen ("data.json", "r");
  if (fp == NULL)
    {
      printf ("Error: Unable to open the file.\n");
      return 1;
    }

  // read the file contents into a string 
  char buffer[1024];
  fread (buffer, 1, sizeof (buffer), fp);
  fclose (fp);

  // parse the JSON data 
  cJSON *json = cJSON_Parse (buffer);
  if (json == NULL)
    {
      const char *error_ptr = cJSON_GetErrorPtr ();
      if (error_ptr != NULL)
	{
	  printf ("Error: %s\n", error_ptr);
	}
      cJSON_Delete (json);
      return 1;
    }

  // access the JSON data 
  cJSON *name = cJSON_GetObjectItemCaseSensitive (json, "name");
  cJSON *age = cJSON_GetObjectItemCaseSensitive (json, "age");
  if (cJSON_IsString (name) && (name->valuestring != NULL))
    {
      printf ("Name: %s\n", name->valuestring);
    }
  if (cJSON_IsNumber (age))
    {
      printf ("Age: %d\n", age->valueint);
    }

  // delete the JSON object 
  cJSON_Delete (json);
  return 0;
}
