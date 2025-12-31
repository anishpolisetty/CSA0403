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
    for(int i = 0; i < f; i++) frame[i] = -1;

    int hit = 0, fault = 0;

    printf("\nPage\tFrames\n");

    for(int i = 0; i < n; i++) {
        int found = -1;

        // Check if page is already in frame (hit)
        for(int j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = j;
                hit++;
                break;
            }
        }

        if(found == -1) {
            // Page fault → find optimal page to replace
            int replace = -1;
            int farthest = i;

            for(int j = 0; j < f; j++) {
                if(frame[j] == -1) { replace = j; break; } // empty slot
            }

            if(replace == -1) {
                int farthest_index = -1;
                for(int j = 0; j < f; j++) {
                    int k;
                    for(k = i + 1; k < n; k++) {
                        if(frame[j] == pages[k])
                            break;
                    }
                    if(k > farthest) {
                        farthest = k;
                        farthest_index = j;
                    }
                }
                replace = farthest_index;
            }

            frame[replace] = pages[i];
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
