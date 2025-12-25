#include <stdio.h>
#include <string.h>

struct directory {
    char fname[10][20];
    int fcount;
};

int main() {
    struct directory dir[10];
    char uname[10][20];
    int ucount, i, j, choice;
    char user[20];

    printf("Enter number of users: ");
    scanf("%d", &ucount);

    for (i = 0; i < ucount; i++) {
        printf("Enter user name: ");
        scanf("%s", uname[i]);

        printf("Enter number of files for %s: ", uname[i]);
        scanf("%d", &dir[i].fcount);

        printf("Enter file names:\n");
        for (j = 0; j < dir[i].fcount; j++) {
            scanf("%s", dir[i].fname[j]);
        }
    }

    while (1) {
        printf("\n1. Display Files\n2. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter user name: ");
            scanf("%s", user);

            for (i = 0; i < ucount; i++) {
                if (strcmp(user, uname[i]) == 0) {
                    printf("Files of %s:\n", uname[i]);
                    for (j = 0; j < dir[i].fcount; j++) {
                        printf("%s\n", dir[i].fname[j]);
                    }
                }
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

