#include <unistd.h>

int main(void) {
    char *file = "echo";
    char *arg1 = "Hello world!";

    execlp(file, file, arg1, NULL);
    return 0;
}
