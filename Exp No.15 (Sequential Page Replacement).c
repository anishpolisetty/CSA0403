#include <stdio.h>

int main() {
    int file_no, start, length, i, j;

    printf("Enter number of files: ");
    scanf("%d", &file_no);

    int files[file_no][3];  // file, start block, length

    for (i = 0; i < file_no; i++) {
        printf("\nEnter File %d starting block: ", i + 1);
        scanf("%d", &files[i][1]);

        printf("Enter File %d length: ", i + 1);
        scanf("%d", &files[i][2]);

        files[i][0] = i + 1;
    }

    printf("\nFile\tStart\tLength\tBlock Numbers\n");
    for (i = 0; i < file_no; i++) {
        printf("F%d\t%d\t%d\t", files[i][0], files[i][1], files[i][2]);

        for (j = 0; j < files[i][2]; j++)
            printf("%d ", files[i][1] + j);

        printf("\n");
    }

    return 0;
}
