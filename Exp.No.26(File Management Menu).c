#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[30], data[200];
    int choice;

    while (1) {
        printf("\n--- File Management Menu ---\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            if (fp) {
                printf("File created successfully.\n");
                fclose(fp);
            }
            break;

        case 2:
            printf("Enter filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "a");
            if (!fp) { printf("File not found!\n"); break; }

            printf("Enter text: ");
            getchar(); 
            fgets(data, sizeof(data), stdin);
            fputs(data, fp);
            printf("Data written.\n");
            fclose(fp);
            break;

        case 3:
            printf("Enter filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "r");
            if (!fp) { printf("File not found!\n"); break; }

            printf("\nContents:\n");
            while (fgets(data, sizeof(data), fp))
                printf("%s", data);

            fclose(fp);
            break;

        case 4:
            printf("Enter filename to delete: ");
            scanf("%s", filename);

            if (remove(filename) == 0)
                printf("File deleted successfully.\n");
            else
                printf("Unable to delete file.\n");
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
