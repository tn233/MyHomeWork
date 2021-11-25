#include <stdio.h>

int main(){
    int a,b,c;
    printf("请输入a值:");
    scanf("%d",&a);
    printf("\n请输入b值:");
    scanf("%d",&b);
    c = a;
    a = b;
    b = c;
    printf("\na和b分别为:%d,%d",a,b);
}