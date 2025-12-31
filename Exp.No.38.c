#include <stdio.h>

int main(){
    int fileBlocks[100] = {0}; // disk blocks 0/1 free/used
    int indexBlock[10]; // index entries for one file
    int fileSize = 5; // number of blocks
    // simple allocation: allocate first fileSize free blocks
    int k=0;
    for(int i=0;i<100 && k<fileSize;i++){
        if(!fileBlocks[i]){ fileBlocks[i]=1; indexBlock[k++]=i; }
    }
    printf("Index block entries for file:\n");
    for(int i=0;i<fileSize;i++) printf("%d ", indexBlock[i]);
    printf("\n");
    return 0;
}
