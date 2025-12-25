#include <stdio.h>

int main() {
    int pages[50], frame[10], n, f, i, j, k = 0, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");
    for (i = 0; i < n; i++) {
        int flag = 0;

        for (j = 0; j < f; j++)
            if (frame[j] == pages[i])
                flag = 1;

        if (!flag) {
            frame[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    return 0;
}
