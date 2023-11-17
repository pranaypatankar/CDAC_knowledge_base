#include <unistd.h>

int main(void) {
    char *file = "/usr/bin/bash";
    char *arg1 = "-c";
    char *arg2 = "echo $ENV1 $ENV2!";
    char *const env[] = {"ENV1=Hello", "ENV2=World", NULL};
	
    execle(file, file, arg1, arg2, NULL, env);

    return 0;
}
