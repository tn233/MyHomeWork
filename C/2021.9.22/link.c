#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    int id;
    char name[10];
    int total_score;
} student;

typedef struct link{
    student *student_info;
    struct link *next;
}link;

link *head;

int create();
int add(link *head,int id,char *name[10],int total_score);
link *find_end(link *head);
link *search(link *head,int id);
int delete(link *head,int id);
link *find(link *head,int id);
int edit(link *head,int id,char *name[10]);
int foreach(link *head);
int length(link *head);
link *findByIndex(link *head,int index);
int findSame(link *head,int id);
link *Max(link *head);
link *Min(link *head);

int main(){
    //后插法
    create();
    add(head,1,"小明",120);
    add(head,2,"小李",135);
    add(head,6,"小刘",165);
    add(head,3,"小张",143);
    add(head,4,"小安",153);
    add(head,4,"小安2",122);
    add(head,5,"小黄",130);
    /**
    printf("%s\n",find(head,3)->student_info->name);
    delete(head,3);
    printf("%s\n",find(head,2)->student_info->name);
    edit(head,5,"tn233[555]");
    printf("%s\n",find(head,5)->student_info->name);
    **/
    printf("长度为:%d\n",length(head));
    foreach(head);
    link *result = findByIndex(head,3);
    printf("下标为3的信息:姓名%s,学号:%d,总成绩:%d\n",result->student_info->name,result->student_info->id,result->student_info->total_score);
    link *find_result = find(head,2);
    printf("学号为2的信息:姓名:%s,总成绩:%d\n",find_result->student_info->name,find_result->student_info->total_score);
    printf("学号为4的信息在表中有%d个\n",findSame(head,4));
    link *max = Max(head);
    printf("总成绩最高:姓名:%s,学号:%d,总成绩:%d\n",max->student_info->name,max->student_info->id,max->student_info->total_score);
    link *min = Min(head);
    printf("总成绩最低:姓名:%s,学号:%d,总成绩:%d\n",min->student_info->name,min->student_info->id,min->student_info->total_score);
    delete(head,4);
    
}

int create(){
    head = (link*)malloc(sizeof(link));
    return 0;
}

int add(link *head,int id,char *name[10],int total_score){
    head = find_end(head);
    head->next = (link*)malloc(sizeof(link));
    head->next->student_info = (student*)malloc(sizeof(student));
    head->next->student_info->id = id;
    head->next->student_info->total_score = total_score;
    strcpy(head->next->student_info->name,name);
    head->next->next = NULL;
}

int delete(link *head,int id){//基于ID的删除，name同理
    head = search(head,id);
    link *tmp = head->next->next;
    free(head->next->student_info);
    free(head->next);
    //free(head->next->student_info);
    head->next = tmp;
    return 0;
}

link *find_end(link *head){//O(n)，找找更好的方法？
    while(head->next != NULL){
        head = head->next;
    }
    return head;
}

link *search(link *head,int id){//返回目标的前一个链表
    while(head != NULL){
        if(head->next->student_info->id == id){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

link *find(link *head,int id){//2.11 - 根据id查节点
    head = search(head,id);
    return head->next;
}

int edit(link *head,int id,char *name[10]){
    head = search(head,id)->next;
    strcpy(head->student_info->name,"\0\0\0\0\0\0\0\0\0\0");//先清空
    strcpy(head->student_info->name,name);//再刷入
    return 0;
}

int destroy(link *head){
    link *tmp = NULL;
    while(head != NULL){
        tmp = head->next;
        free(head->student_info);
        free(head->next);
        head = tmp;
    }
    return 0;
}

int foreach(link *head){//2.8 - 遍历
    head = head->next;//因为有个头节点没有内容，手动换到第一个有内容的节点
    printf("---foreach---\n");
    while(head != NULL){
        printf("姓名:%s,学号:%d,总成绩:%d\n",head->student_info->name,head->student_info->id,head->student_info->total_score);
        head = head->next;
    }
    printf("---end---\n");
    return 0;
}

int length(link *head){//2.9 - 长度
    int len = 0;
    while(head->next != NULL){
        len++;
        head = head->next;
    }
    return len;
}

link *findByIndex(link *head,int index){//2.10 - 通过链表下标查询
    int i = 0;
    for(;i < index;i++){
        head = head->next;
    }
    return head;
}

int findSame(link *head,int id){//2.10(2) - 寻找相同学号的节点个数
    head = head->next;//因为有个头节点没有内容，手动换到第一个有内容的节点
    int same = 0;
    while(head != NULL){
        if(head->student_info->id == id){
            same++;
        }
        head = head->next;
    }
    return same;
}

link *Max(link *head){//总成绩最大
    int score = 0;
    link *result = NULL;
    head = head->next;//因为有个头节点没有内容，手动换到第一个有内容的节点
    while(head != NULL){
        if(head->student_info->total_score > score){
            result = head;
            score = head->student_info->total_score;
        }
        head = head->next;
    }
    return result;
}

link *Min(link *head){//总成绩最小
    link *result = NULL;
    head = head->next;//因为有个头节点没有内容，手动换到第一个有内容的节点
    int score = head->student_info->total_score;//取最小值，用第一个值作为平均数
    while(head != NULL){
        if(head->student_info->total_score <= score){
            result = head;
            score = head->student_info->total_score;
        }
        head = head->next;
    }
    return result;
}