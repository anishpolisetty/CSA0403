#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, disk_size, i, j, temp;
    int req[20], total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    /* Sort the request array */
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    /* Move towards higher tracks first */
    for (i = 0; i < n; i++) {
        if (req[i] >= head) {
            total += abs(req[i] - head);
            head = req[i];
        }
    }

    /* Go to end of disk */
    total += abs((disk_size - 1) - head);
    head = disk_size - 1;

    /* Move towards lower tracks */
    for (i = n - 1; i >= 0; i--) {
        if (req[i] < head) {
            total += abs(req[i] - head);
            head = req[i];
        }
    }

    printf("Total head movement: %d\n", total);

    return 0;
}

