#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int choice; char name[50], data[200];
    while(1){
        printf("\n1.Create/Write 2.Read 3.Delete 4.Exit\nChoice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Filename: "); scanf("%s",name);
            FILE *f = fopen(name,"w");
            printf("Enter text (single line): "); getchar(); fgets(data,sizeof(data),stdin);
            fputs(data,f); fclose(f); printf("Written.\n");
        } else if(choice==2){
            printf("Filename: "); scanf("%s",name);
            FILE *f = fopen(name,"r");
            if(!f){ printf("Not found\n"); continue; }
            printf("Content:\n"); while(fgets(data,sizeof(data),f)) printf("%s",data);
            fclose(f);
        } else if(choice==3){
            printf("Filename: "); scanf("%s",name);
            if(remove(name)==0) printf("Deleted\n"); else printf("Delete failed\n");
        } else break;
    }
    return 0;
}
