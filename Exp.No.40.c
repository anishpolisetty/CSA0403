#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b){ return (*(int*)a - *(int*)b); }

int main(){
    int n, head, disk_size;
    int req[50];
    printf("Disk size: "); scanf("%d",&disk_size);
    printf("No. of requests: "); scanf("%d",&n);
    printf("Enter requests: ");
    for(int i=0;i<n;i++) scanf("%d",&req[i]);
    printf("Head pos: "); scanf("%d",&head);
    qsort(req, n, sizeof(int), cmp);
    // find split point
    int idx=0; while(idx<n && req[idx] < head) idx++;
    int total = 0;
    // move right to end
    for(int i=idx;i<n-1;i++){ total += abs(req[i+1]-req[i]); }
    if(idx < n){ total += abs((disk_size-1) - ( (idx<n)? req[n-1]: head )); }
    // jump to start (circular)
    if(idx>0){ total += (disk_size-1); total += abs(req[0]-0);
        for(int i=0;i<idx-1;i++) total += abs(req[i+1]-req[i]);
    }
    printf("Total head movement (approx): %d\n", total);
    return 0;
}
