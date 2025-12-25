#include <stdio.h>

int main() {
    int pages[50], frame[10], n, f;
    int i, j, k, faults = 0;

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
            int index = -1, farthest = i + 1;
            for (j = 0; j < f; j++) {

                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            index = j;
                        }
                        break;
                    }
                }

                if (k == n) {
                    index = j;
                    break;
                }
            }

            frame[index] = pages[i];
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
