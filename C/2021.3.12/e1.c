#include <stdio.h>

int main(){
    char a;
    printf("请输入大写字母:");
    scanf("%c",&a);
    a += 32;
    printf("小写字母为:%c",a);
    return 0;
}