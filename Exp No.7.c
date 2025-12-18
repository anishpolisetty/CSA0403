#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello from Parent!";
    char read_msg[50];

    if (pipe(fd) == -1) {
        printf("Pipe creation failed\n");
        return 1;
    }

    int pid = fork();

    if (pid == 0) {
        close(fd[1]);
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
    } 
    else {
        close(fd[0]);
        write(fd[1], write_msg, sizeof(write_msg));
        printf("Parent sent: %s\n", write_msg);
    }
    return 0;
}
