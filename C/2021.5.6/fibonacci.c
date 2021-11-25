#include <stdio.h>
#include <math.h>

/**
斐波那契数列

1 -> 1
2 -> 1
3 -> f(2)+f(1) -> 1+1 -> 2
4 -> f(3)+f(2) -> 2+1 -> 3
5 -> f(4)+f(3) -> 3+2 -> 5
6 -> f(5)+f(4) -> 5+3 -> 8

0 -> 0
1 -> 1
2 -> f(1)+f(0) -> 1+0 -> 1
3 -> f(2)+f(1) -> 1+1 -> 2
4 -> f(3)+f(2) -> 2+1 -> 3
5 -> f(4)+f(3) -> 3+2 -> 5

[0,1,1,2,3,5,8]
 0,1,2,3,4,5,6
**/

int fib(int n);//function declear

int main(){
    int i,m,result;
    printf("input:");
    scanf("%d",&m);
    i = 1;
    while((result = fib(i)) < m){
        i++;
    }
    printf("result:%d\n",result);
    return 0;
}

int fib(int n){
    int f;
    if(n==1||n==2){
        f = 1;
    }else{
        f = fib(n - 1) + fib(n - 2);
    }
    return f;
}