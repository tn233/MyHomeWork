#include <stdio.h>

int abcdefg(int a,int b);

int main(){
    int p;
    p = abcdefg(123,345);
    printf("%d",p);
}

int abcdefg(int a,int b){
    return a>b?a:b;//三目运算符
}