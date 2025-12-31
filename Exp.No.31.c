#include <stdio.h>

int main() {
    int n, f;
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frame[f];
    for(int i = 0; i < f; i++) frame[i] = -1;  // initialize frames

    int hit = 0, fault = 0, index = 0;

    printf("\nPage\tFrames\n");

    for(int i = 0; i < n; i++) {
        int found = 0;
        // Check if page is already in frame (Hit)
        for(int j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                hit++;
                break;
            }
        }

        if(!found) {
            // Page fault → replace using FIFO
            frame[index] = pages[i];
            index = (index + 1) % f;
            fault++;
        }

        printf("%d\t", pages[i]);
        for(int j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Hits: %d\n", hit);
    printf("Total Page Faults: %d\n", fault);

    return 0;
}
