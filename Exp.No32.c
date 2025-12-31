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

    int frame[f], recent[f];
    for(int i = 0; i < f; i++) frame[i] = -1;

    int hit = 0, fault = 0;

    printf("\nPage\tFrames\n");

    for(int i = 0; i < n; i++) {
        int found = -1;
        // Check if page is already in frame
        for(int j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = j;
                hit++;
                break;
            }
        }

        if(found != -1) {
            // Update recent usage
            recent[found] = i;
        } else {
            // Page fault → find least recently used
            int lru_index = 0;
            int min = recent[0];
            for(int j = 1; j < f; j++) {
                if(recent[j] < min) {
                    min = recent[j];
                    lru_index = j;
                }
            }

            // If empty slot exists
            int empty = -1;
            for(int j = 0; j < f; j++) {
                if(frame[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) lru_index = empty;

            frame[lru_index] = pages[i];
            recent[lru_index] = i;
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
