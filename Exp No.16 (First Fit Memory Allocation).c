#include <stdio.h>

int main() {
    int m, n, i, j;
    int blockSize[10], processSize[10];
    int allocation[10];

    /* Initialize allocation array */
    for (i = 0; i < 10; i++)
        allocation[i] = -1;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each block:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    /* First Fit Allocation */
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

