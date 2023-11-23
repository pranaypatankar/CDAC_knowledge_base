#include <unistd.h>

int main(void) {
    char *file = "/usr/bin/echo";
    char *arg1 = "Hello world!";

    execl(file, file, arg1, NULL);

    return 0;
}
