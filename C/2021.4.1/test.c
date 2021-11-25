#include <stdio.h>

int main(){
    long n,m;
    int count = 0;
    printf("input:");
    scanf("%ld",&n);
    m = n;
    if(n<0){
        n = -n;
    }
    
    do{
        n /= 10;
        count++;
    }while(n!=0);
    printf("do while output:%ld,%d\n",m,count);

    n = m;
    count = 0;
    while(n > 0){
        n /= 10;
        count++;
    }
    printf("while output:%ld,%d",m,count);
}