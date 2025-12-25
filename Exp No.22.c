#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    int fd = open("sample.txt", O_RDONLY);
    struct stat st;
    DIR *d;
    struct dirent *de;

    fcntl(fd, F_GETFL);

    lseek(fd, 5, SEEK_SET);

    stat("sample.txt", &st);
    printf("File size: %ld bytes\n", st.st_size);

    d = opendir(".");
    printf("Files in current directory:\n");
    while ((de = readdir(d)) != NULL)
        printf("%s\n", de->d_name);

    closedir(d);
    close(fd);
    return 0;
}
