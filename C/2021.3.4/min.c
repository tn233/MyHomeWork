/** 取三个数字的最小值
 * Author 邓一哲 2020030311101
 * Date: 2021.3.4
 **/

#include <stdio.h>

int main(){
    int a,b,c;
    printf("请输入三个数字(比如1,2,3):");
    scanf("%d,%d,%d",&a,&b,&c);
    if(((a+b)/2) < c){
        if(a > b){
            printf("%d",b);
        }else{
            printf("%d",a);
        }
    }else{
       printf("%d",c); 
    }
    return 0;
}