#include <stdio.h>

int main(){
    int i = 1,a = 1,b = 1;
    for(;a<10;){
        i = b;
        a = b;
        for(;i<10;i++){
            printf("|%d*%d=%d",a,i,(i*a));
        }
        printf("\n");
        b++;
    }
    return 0;
}