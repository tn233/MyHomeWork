#include<stdio.h>
#include<string.h>
int string(char string[],char main_string[]);
//KMP算法
int main(){
    char string1[] = "abcdefgabcd";
    char string2[] = "abc";
    int a = string(string2,string1);
    printf("匹配个数:%d",a);
}

int string(char string[],char main_string[]){
    int i = 0,total = 0;
    //printf("%d",strlen(main_string));
    while(i < strlen(main_string)){
        if(main_string[i] == string[0]){
            int j = 0,d = i;
            for(;j < strlen(string);j++){
                //printf("%c,%c\n",string[j],main_string[d]);
                printf("%d,%d\n",j,d);
                if(main_string[d] != string[j]){
                    break;
                }else if(j == strlen(string) - 1){
                    total++;
                    i = d;
                    break;
                }
                d++;
            }
        }
        i++;
    }
    return total;
}