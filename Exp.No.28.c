#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

void print_permissions(mode_t m) {
    printf( (m & S_IRUSR) ? "r" : "-");
    printf( (m & S_IWUSR) ? "w" : "-");
    printf( (m & S_IXUSR) ? "x" : "-");
    printf( (m & S_IRGRP) ? "r" : "-");
    printf( (m & S_IWGRP) ? "w" : "-");
    printf( (m & S_IXGRP) ? "x" : "-");
    printf( (m & S_IROTH) ? "r" : "-");
    printf( (m & S_IWOTH) ? "w" : "-");
    printf( (m & S_IXOTH) ? "x" : "-");
}

int main() {
    DIR *d;
    struct dirent *de;
    struct stat st;

    d = opendir(".");
    if (!d) return 1;

    printf("Type Permissions Size Name\n");

    while ((de = readdir(d)) != NULL) {
        stat(de->d_name, &st);

        // File type
        printf(S_ISDIR(st.st_mode) ? "DIR  " : "FILE ");

        // Permissions
        print_permissions(st.st_mode);
        printf(" ");

        // Size
        printf("%6ld ", st.st_size);

        // File name
        printf("%s\n", de->d_name);
    }

    closedir(d);
    return 0;
}
