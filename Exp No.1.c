#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before fork\n");

    int pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
    }
    else if (pid == 0) {
        printf("This is Child Process. PID = %d\n", getpid());
    }
    else {
        printf("This is Parent Process. PID = %d\n", getpid());
    }

    return 0;
}
