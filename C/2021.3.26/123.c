#include <stdio.h>

int main(){
    char a[100] = {0};
    int i=0,total=0,tmp=0,tmp2=0;
    scanf("%s",&a);
    while(i<sizeof(a) && a[0]!=0){
        switch(a[i]){
            case 0:
                printf("%d",total);
                return 0;
            break;
            case '(':
                tmp = 0;
                tmp2 = 0;
            break;
            case ')':
                if(tmp>=tmp2){
                    total+=tmp;
                }else{
                    total+=tmp2;
                }
            break;
            case '|':
                tmp2 = tmp;
                tmp = 0;
            break;
            default:
                tmp++;
            break;
        }
        i++;
    }
    printf("%d",total);
    return 0;
}