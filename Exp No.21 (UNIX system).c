 #include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("demo.txt", O_CREAT | O_WRONLY, 0644);
    write(fd, "Welcome to UNIX file management\n", 32);
    close(fd);

    fd = open("demo.txt", O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("File Content: %s\n", buffer);
    close(fd);

    return 0;
}
