#include <stdio.h>
#include <stdlib.h>

typedef struct inner{
    int data;
    struct inner *next;
}list;

list *init();
int push(list *head,int number);
int pop(list *head);
int _10to2(list *q,int input);
int _10to8(list *q,int input);
int _10to16(list *q,int input);

list *head;
int pointer;

int main(){
    head = init();
    int input = 10,option = 2;
    
    
    printf("请输入十进制:");
    scanf("%d",&input);
    
    printf("请输入转换进制(2,8,16):");
    scanf("%d",&option);
    switch(option){
        case 2:
            _10to2(head,input);
        break;
        case 8:
            _10to8(head,input);
        break;
        case 16:
            _10to16(head,input);
        break;
        default:
            printf("input err!");
    }

    return 0;
}

list *init(){
    return (list*)malloc(sizeof(list));
}

int push(list *head,int number){//入栈
    list *tmp = head->next;
    head->next = (list*)malloc(sizeof(list));
    head->next->data = number;
    head->next->next = tmp;
    pointer++;
    return 0;
}

int pop(list *head){//出栈
    pointer--;
    int result = head->next->data;
    head->next = head->next->next;
    free(head->next);
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
   
    while(pointer > 0){
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
   
    while(pointer > 0){
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
   
    while(pointer > 0){
        int result = pop(q);
        if(result >= 10){
            printf("%c",result+55);
        }else{
            printf("%d",result);
        }
        
    }
}