#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int number;
    struct LNode *next;
}LNode,*Linklist;

int Init(Linklist *L){
    L = (Linklist*)malloc(sizeof(LNode));
    printf("inner:%d\n",L);
}

int main(){
    Linklist L;
    printf("%d\n",L);
    Init(L);
    printf("%d",L);
}