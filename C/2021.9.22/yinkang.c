#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 100

typedef struct node
{ int num;
  char name[MAXLEN];
  int score;
  struct node *next;
}list,LNode,*LinkList;
LinkList L;
//LNode *p;
list *create()
{list *head,*p,*r;
 int i,n;
 head=(list*)malloc(sizeof(list));
 head->next=NULL;
 r=head;
 printf("请输入学生人数:\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
   { p=(list*)malloc(sizeof(list));
     printf("请输入学生的学号:\n");
     scanf("%d",&p->num);
     printf("请输入学生的姓名:\n");
     scanf("%s",p->name);
     printf("请输入学生的成绩:\n");
     scanf("%d",&p->score);
     p->next=NULL;
     r->next=p;
	 r=r->next;
      }
    return(head);
    }
    void find(list *h)
    {
      int k;
      list *p;
      p=h->next;
      printf("请输入要查找的学号:\n");
      scanf("%d",&k);
      while(p!=NULL&&p->num!=k)
            p=p->next;
	  if(p)
	  {  printf("学号\t 姓名\t 成绩\n");
	     printf("%d\t%s\t%d\n",p->num,p->name,p->score);
	   } 
	   else
	      printf("无\n");
	}
	void output(list *h)
	{
		list *p;
		p=h->next;
	   if(p==NULL)
	       printf("无!\n");
	    while(p!=NULL)
	    { printf("学号\t姓名\t成绩\n");
		  printf("%d\t%s\t%d\n",p->num,p->name,p->score);
		  p=p->next;
		}
	}
	int findmaxmin(list *h)
	{	int max,min;
		list *p = h->next;
		max = p->score;
		min = p->score;
		while(p){	
			if(p->score > max){
				max = p->score;
			}else if(p->score < min){
				min = p->score;
			}
			p = p->next;  
		}
		printf("max=%d,min=%d\n",max,min);
	}
  
void main()
{
 list *p;
 int k;
 while(1)
 {
 	printf("1.登记成绩\n");
 	printf("2.查询成绩\n");
 	printf("3.输出成绩\n");
 	printf("4.最大最小成绩\n");
 	printf("5.退出程序\n");
 	printf("选号\n");
 	scanf("%d",&k);
 	switch(k)
 	{
 		case 1:p=create();break;
 		case 2:find(p);break;
 		case 3:output(p);break;
 		case 4:findmaxmin(p);break;
 		case 5:exit(0);
 	  default:printf("选错了，给我重新选！\n");
	 }
 }
}