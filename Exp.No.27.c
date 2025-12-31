#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void print_permissions(mode_t m) {
    printf((m & S_IRUSR) ? "r" : "-");
    printf((m & S_IWUSR) ? "w" : "-");
    printf((m & S_IXUSR) ? "x" : "-");
    printf((m & S_IRGRP) ? "r" : "-");
    printf((m & S_IWGRP) ? "w" : "-");
    printf((m & S_IXGRP) ? "x" : "-");
    printf((m & S_IROTH) ? "r" : "-");
    printf((m & S_IWOTH) ? "w" : "-");
    printf((m & S_IXOTH) ? "x" : "-");
}

int main() {
    DIR *d;
    struct dirent *de;
    struct stat st;

    d = opendir(".");
    if (d == NULL) {
        perror("opendir failed");
        return 1;
    }

    printf("Type Permissions   Size     Name\n");
    printf("--------------------------------------\n");

    while ((de = readdir(d)) != NULL) {

        if (stat(de->d_name, &st) == -1) {
            perror("stat failed");
            continue;
        }

        /* File type */
        if (S_ISDIR(st.st_mode))
            printf("DIR  ");
        else
            printf("FILE ");

        /* Permissions */
        print_permissions(st.st_mode);
        printf(" ");

        /* File size */
        printf("%8ld ", (long)st.st_size);

        /* File name */
        printf("%s\n", de->d_name);
    }

    closedir(d);
    return 0;
}

