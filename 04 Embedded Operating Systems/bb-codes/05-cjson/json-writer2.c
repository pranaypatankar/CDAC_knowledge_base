#include <stdio.h>
#include <cjson/cJSON.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int
main ()
{
  // create a cJSON object 
  cJSON *json = cJSON_CreateObject ();
  cJSON_AddStringToObject (json, "name", "John Doe");
  cJSON_AddNumberToObject (json, "age", 30);
  cJSON_AddStringToObject (json, "email", "john.doe@example.com");

  // convert the cJSON object to a JSON string 
  char *json_str = cJSON_Print (json);

  int flags = O_CREAT | O_RDWR | O_TRUNC;
  int mode = S_IRUSR | S_IWUSR | S_IRGRP;
  // write the JSON string to a file 
  int fd = open ("data.json", flags,mode);
  if (fd == -1)
    {
      printf ("Error: Unable to open the file.\n");
      return 1;
    }
  write (fd, json_str,strlen(json_str));
  //fputs (json_str, fd);
  close (fd);

  // free the JSON string and cJSON object 
  cJSON_free (json_str);
  cJSON_Delete (json);
  
  return 0;
}
