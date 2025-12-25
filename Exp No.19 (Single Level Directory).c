#include <stdio.h>
#include <string.h>

int main() {
    char files[20][20];
    int n, i, choice;

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter file names:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", files[i]);
    }

    while (1) {
        printf("\n1. Display Files\n2. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nFiles in Single Level Directory:\n");
            for (i = 0; i < n; i++) {
                printf("%s\n", files[i]);
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

