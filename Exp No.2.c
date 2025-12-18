#include <stdio.h>

int main() {
    FILE *src, *dest;
    char ch;

    src = fopen("source.txt", "r");
    dest = fopen("destination.txt", "w");

    if (!src || !dest) {
        printf("Error in opening file!\n");
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully!\n");

    fclose(src);
    fclose(dest);

    return 0;
}
