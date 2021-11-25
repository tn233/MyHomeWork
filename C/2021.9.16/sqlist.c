#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
typedef struct STU{
    char name[10];
    int age;
    int stu_id;
    float score;
}student;

typedef struct{
    student data[100];
    int length;
}sqlist;

void create (sqlist *);
void add (sqlist *);
void print (sqlist *);
void delete (sqlist *);
void search (sqlist *);
void menu (void);

int main(void)
{
    sqlist L;
    sqlist * list = &L;
    int a;
    while (1){
        menu();
        printf("\n\n请输入要运行的序号：");
        scanf("%d", &a);
        switch (a)
        {
            case 1:
            create(list);
            break;
            case 2:
            add(list);
            break;
            case 3:
            search(list);
            break;
            case 4:
            delete(list);
            break;
            case 5:
            print(list);
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("Error");
            break;
        } 
    }
    
    return 0;
}

void create (sqlist *list)
{
    int  n;
    list->length = 0;
    sqlist *p = list;
    printf("请输入需要参与统计学生的数量：");
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        printf("\n\n请输入第%.3d个学生的姓名：", i+1);
        scanf("%s", p->data[i].name);
        printf("请输入第%.3d个学生的年龄：", i+1);
        scanf("%d", &p->data[i].age);
        printf("请输入第%.3d个学生的学号：", i+1);
        scanf("%d", &p->data[i].stu_id);
        printf("请输入第%.3d个学生的成绩：", i+1);
        scanf("%f", &p->data[i].score);
    }
    list->length = n;
    getchar();
    getchar();
    system("cls");
}

void add (sqlist *list)
{
    if (MAXLEN<list->length){
        printf("表满，无法插入！");
        return ;
    }

    int k;
    printf("请输入需要插入的位置：");
    scanf("%d", &k);

    for (int i=list->length; i>=k; i--){
        list->data[i] = list->data[i-1];
    }

        
        printf("第%.3d个学生的姓名：\n", k);
        scanf("%s", list->data[k-1].name);
        printf("第%.3d个学生的年龄：\n", k);
        scanf("%d", &list->data[k-1].age);
        printf("第%.3d个学生的学号：\n", k);
        scanf("%d", &list->data[k-1].stu_id);
        printf("第%.3d个学生的成绩：\n", k);
        scanf("%f", &list->data[k-1].score);
        list->length += 1;
        printf("已完成插入，表内现有%d个学生信息\n", list->length);
        getchar();
        getchar();
        system("cls");
}



void print (sqlist *list)
{
    for (int i=0; i<list->length; i++){
        printf("第%.3d个学生的姓名：%s\n", i+1, list->data[i].name);
        printf("第%.3d个学生的年龄：%d\n", i+1, list->data[i].age);
        printf("第%.3d个学生的学号：%d\n", i+1, list->data[i].stu_id);
        printf("第%.3d个学生的成绩：%.2f\n", i+1, list->data[i].score);
        printf("线性表现有元素个数：%d\n\n", list->length);
    }
    getchar();
    getchar();
    system("cls");
}
void delete (sqlist *list)
{
    int k;
    char name[10];
    printf("请输入需要查询学生的姓名：");
    scanf("%s", name);
    int i = 0, ss=0;
    for (i; i<list->length; i++){
        if (strcmp(list->data[i].name, name)==0){
            k = i;
            ss = 1;
            break;
        }
       
    }
     if(ss==0){
            printf("未找到该学生.");
            getchar();
            system("cls");
            return ;
        }
    for (int i=k; i<list->length; i--){
        list->data[k] = list->data[k+1];
    }
    list->length-=1;
    printf("删除完成！\n");
    getchar();
    getchar();
    system("cls");
}

void search (sqlist *list)
{
    int id;
    getchar();
    printf("请输入需要查询学生的学号：");
    scanf("%d", &id);
    int i=0, s=0;
    while (i<list->length+1){
        if (list->data[i].stu_id==id){
            s = 1;
            printf("第%.3d个学生的姓名：%s\n", i+1, list->data[i].name);
            printf("第%.3d个学生的年龄：%d\n", i+1, list->data[i].age);
            printf("第%.3d个学生的学号：%d\n", i+1, list->data[i].stu_id);
            printf("第%.3d个学生的成绩：%.2f\n\n", i+1, list->data[i].score);
            break;
        }
        
        
        i++;

    }
    if (s == 0) {
            printf("未找到该学生！");
            getchar();
            getchar();
            system("cls");
            return ;
        }
    
    printf("查找完成!\n");
    getchar();
    getchar();
    system("cls");
}

void menu (void)
{
    printf("简单的学生信息管理系统(基于顺序表)\n\n");
    printf("1.创建顺序表.\t\t2.添加新成员.\n");
    printf("3.查找成员信息.\t\t4.删除成员信息.\n");
    printf("5.打印成员信息\t\t6.退出程序.\n\n");
    printf("Never Settle.");

}