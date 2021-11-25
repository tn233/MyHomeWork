#include <stdio.h>
#include <string.h>
//十进制转二进制，八进制，十六进制
typedef struct{
    int data[100];
    int pointer;
}list;

int push(list *list,int number);
int pop(list *list);
list init();
int _10to2(list *q,int input);
int _10to8(list *q,int input);
int _10to16(list *q,int input);
/**
typedef struct student{
    int id;
    char name[10];
    int total_score;
} student;
**/

int main(){
    list q = init();
    int input = 10,option;
    
    printf("请输入十进制:");
    scanf("%d",&input);
    
    printf("请输入转换进制(2,8,16):");
    scanf("%d",&option);
    switch(option){
        case 2:
            _10to2(&q,input);
        break;
        case 8:
            _10to8(&q,input);
        break;
        case 16:
            _10to16(&q,input);
        break;
        default:
            printf("input err!");
    }

    return 0;
    //printf("请输入待转换进制(2,8,10,16):");
    //scanf("%d",&option);
    //printf("bingo");
}

list init(){
    list q;
    q.pointer = 0;
    return q;
}

int push(list *list,int number){//入栈
    list->data[list->pointer] = number;
    list->pointer++;
    return 0;
}

int pop(list *list){//出栈
    list->pointer--;
    int result = list->data[list->pointer];
    list->data[list->pointer] = -1;
    
    return result;
}

int _10to2(list *q,int input){
    while(1){
        //printf("%d",input);
        push(q,input%2);
        //printf("%d",input%2);
        if(input / 2 == 0){
            break;
        }
        input = input/2;
    }
    
    printf("10 to 2:");
   
    while(q->pointer > 0){
        int result = pop(q);
        printf("%d",result);
    }
}

int _10to8(list *q,int input){
    while(1){
        //printf("%d",input);
        push(q,input%8);
        //printf("%d",input%2);
        if(input / 8 == 0){
            break;
        }
        input = input/8;
    }
    
    printf("10 to 8:");
   
    while(q->pointer > 0){
        int result = pop(q);
        printf("%d",result);
    }
}

int _10to16(list *q,int input){
    while(1){
        //printf("%d",input);
        if(input%16 >= 10){
            push(q,input%16);
        }else{
            push(q,input%16);
        }
        //printf("%d",input%2);
        if(input / 16 == 0){
            break;
        }
        input = input/16;
    }

    printf("10 to 16:");
   
    while(q->pointer > 0){
        int result = pop(q);
        if(result >= 10){
            printf("%c",result+55);
        }else{
            printf("%d",result);
        }
        
    }
}