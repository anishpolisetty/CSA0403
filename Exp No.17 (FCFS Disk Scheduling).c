#include <stdio.h>

int main() {
    int i, j, n, head, size, temp;
    int rq[20], total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &rq[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    /* Sort request queue */
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (rq[i] > rq[j]) {
                temp = rq[i];
                rq[i] = rq[j];
                rq[j] = temp;
            }
        }
    }

    /* Service requests to the right of head */
    for (i = 0; i < n; i++) {
        if (rq[i] >= head) {
            total += rq[i] - head;
            head = rq[i];
        }
    }

    /* Jump to beginning */
    total += (size - 1) - head;
    head = 0;
    total += (size - 1);

    /* Service remaining requests */
    for (i = 0; i < n; i++) {
        if (rq[i] < head) {
            total += rq[i] - head;
            head = rq[i];
        }
    }

    printf("Total head movement: %d\n", total);

    return 0;
}

