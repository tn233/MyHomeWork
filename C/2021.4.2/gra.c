#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int a=1,b=1,c=1,d;
    char *happy = (char *)malloc(20);
    for(;a<=5;a++){
        strcat(happy,"*");
    }
    for(;b<=5;b++){
        c = 1;
        for(;c<=b;c++){
            printf(" ");
        }
        printf("%s\n",happy);
    }
    return 0;
}