#include <unistd.h>

int main(void) {
    char *file = "/usr/bin/bash";
    char *const args[] = {"/usr/bin/bash", "-c", "echo Hello $ENV!", NULL};
    char *const env[] = {"ENV=World", NULL};
	
    execve(file, args, env);

    return 0;
}
