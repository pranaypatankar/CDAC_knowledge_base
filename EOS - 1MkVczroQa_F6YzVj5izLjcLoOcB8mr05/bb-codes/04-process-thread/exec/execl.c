#include <unistd.h>

int main(void) {
    char *file = "/usr/bin/echo";
    char *const args[] = {"/usr/bin/echo", "Hello world!", NULL};
	
    execv(file, args);

    return 0;
}
