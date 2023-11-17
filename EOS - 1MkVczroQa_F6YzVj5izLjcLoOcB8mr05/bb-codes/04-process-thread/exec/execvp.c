#include <unistd.h>

int main(void) {
    char *file = "echo";
    char *const args[] = {"/usr/bin/echo", "Hello world!", NULL};
	
    execvp(file, args);

    return 0;
}
