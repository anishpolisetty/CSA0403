#include <stdio.h>

typedef struct { int dataBlock; int next; } Node;

int main(){
    int disk[100] = {0}; // 0 free
    Node link[100]; for(int i=0;i<100;i++){ link[i].next = -1; link[i].dataBlock = i; }
    // allocate blocks 10->25->40 as a file
    int start = 10; link[10].next = 25; link[25].next = 40; link[40].next = -1;
    printf("File blocks: ");
    int cur = start;
    while(cur != -1){ printf("%d ", link[cur].dataBlock); cur = link[cur].next; }
    printf("\n");
    return 0;
}
