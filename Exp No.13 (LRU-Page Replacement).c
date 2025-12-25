#include <stdio.h>

int main() {
    int pages[50], frame[10], count[10], n, f;
    int i, j, faults = 0, next = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frame[i] = -1;
        count[i] = 0;
    }

    printf("\nPage\tFrames\n");
    for (i = 0; i < n; i++) {
        int flag = 0;

        for (j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                count[j] = next++;
                break;
            }
        }

        if (!flag) {
            int min = 0;
            for (j = 1; j < f; j++)
                if (count[j] < count[min])
                    min = j;

            frame[min] = pages[i];
            count[min] = next++;
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
