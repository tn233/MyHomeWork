#include <stdio.h>

enum PA{
    apple=1,banana,coconunct,drink,easy//生成一个类似于struct的递增枚举，从apple=1开始（也可以从中途赋值）
} happy;

int main(){
    int a = apple;
    for(;a<easy;a++){
        //printf("%d",a);
    }
    printf("%ld",sizeof("china"));//字符会带一个终止符，所以为6位而不是5位
    return 0;
}