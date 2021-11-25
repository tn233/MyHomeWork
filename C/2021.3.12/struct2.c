#include <stdio.h>
#include <string.h>

struct Banana
{
    int id;
    char abc[100];
};

int main(){
    struct Banana b;
    b.id = 8888;
    strcpy(b.abc,"banana!!!!");
    printf("%d",b.id);
    //adbc(&b);
    return 0;
}

int abdc(struct Banana *a){
    printf("abc:%s\n",a->abc);
    printf("id:%d\n",a->id);
    return 0;
}