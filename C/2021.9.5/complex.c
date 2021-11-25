#include "stdio.h"
#include "stdlib.h"
typedef struct{
    float real;
    float image;
}complex,*complex_ptr;

void C_Sum(complex_ptr c_ptr,complex com1,complex com2){
    c_ptr->real=com1.real+com2.real;
    c_ptr->image=com1.image+com2.image;
}

void C_Difference(complex_ptr c_ptr,complex com1,complex com2){
    c_ptr->real=com1.real-com2.real;
    c_ptr->image=com1.image-com2.image;
}

void C_product(complex_ptr c_ptr,complex com1,complex com2){
    c_ptr->real=com1.real*com2.real-com1.image*com2.image;
    c_ptr->image=com1.real*com2.image+com1.image*com2.real;
}

int main(){
    int choice;
	complex com1,com2;
	complex_ptr c_ptr;
	c_ptr=(complex_ptr)malloc(sizeof(complex));
	printf("\n---------Menu---------");
	printf("\n    1.复数相加");
	printf("\n    2.复数相减");
	printf("\n    3.复数相乘");
	printf("\n    4.退出");
	printf("\n----------------------\n");
	printf("请选择功能:");
	scanf("%d",&choice);
	while(choice!=4)
	{
		printf("输入第一个复数:\n");
		printf("实部:\n");
		scanf("%f",&com1.real);
		printf("虚部:\n");
		scanf("%f",&com1.image);
		printf("输入第二个复数:\n");
		printf("实部:\n");
		scanf("%f",&com2.real);
		printf("虚部:\n");
		scanf("%f",&com2.image);
		switch(choice){
			case 1:
				C_Sum(c_ptr,com1,com2);
				printf(c_ptr);
                continue;
			break;
			case 2:
				C_Difference(c_ptr,com1,com2);
				printf(c_ptr);
                continue;
			break;
			case 3:
				C_product(c_ptr,com1,com2);
				printf(c_ptr);
                continue;
			break;	
            case 4:
            break;
		}	
	}
}