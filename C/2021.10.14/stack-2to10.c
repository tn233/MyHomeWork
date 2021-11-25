#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct inner{
    int data;
    struct inner *next;
}list;

list *init();
int push(list *head,int number);
int pop(list *head);
int _2to10(list *q,int input);

list *head;
int pointer;

int main(){
    head = init();
    int input = 1010;
    /**
    printf("请输入二进制:");
    scanf("%d",&input);
    **/
    _2to10(head,input);
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

int _2to10(list *q,int input){
    while(1){
        //printf("%d",input);
        push(q,input%10);
        //printf("%d",input%2);
        if(input / 10 < 1){
            break;
        }
        input = input/10;
    }
    
    printf("2 to 10:");
    int total = 0,pos = 0;
    while(pointer > 0){
        int result = pop(q);
        total += result * pow(2,pos);//但这里出现了问题，输出结果一直不对
        pos++;
    }
    printf("%d",total);
}

