#include <stdio.h>
#include <string.h>
struct Apple
{
    int id;
    char abc[100];
};

int main(){
    struct Apple a;
    strcpy(a.abc,"hello");//string
    a.id = 123123;//int
    printf("%d",a.id);
    printf("%s",a.abc);
    return 0;
}