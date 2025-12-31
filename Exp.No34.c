#include <stdio.h>

int find_best(int blocks[], int b, int size) {
    int idx=-1, best=1<<30;
    for(int i=0;i<b;i++) if(blocks[i]>=size && blocks[i]-size < best){ best = blocks[i]-size; idx=i; }
    return idx;
}

int main(){
    int blocks[] = {100, 500, 200, 300, 600};
    int b = 5;
    int procs[] = {212,417,112,426}, p=4;
    int alloc[4]; for(int i=0;i<p;i++) alloc[i]=-1;
    for(int i=0;i<p;i++){
        int idx=find_best(blocks,b,procs[i]);
        if(idx!=-1){ alloc[i]=idx; blocks[idx]-=procs[i]; }
    }
    printf("Process\tSize\tAllocatedBlock\n");
    for(int i=0;i<p;i++) printf("%d\t%d\t%s\n", i+1, procs[i], alloc[i]==-1?"Not Allocated":"Allocated");
    return 0;
}
