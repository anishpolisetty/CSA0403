#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("demo.txt", "r");
    char line[200], pattern[50];

    printf("Enter pattern: ");
    scanf("%s", pattern);

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern))
            printf("%s", line);
    }
    fclose(fp);
    return 0;
}
