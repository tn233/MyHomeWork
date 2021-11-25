/*
编写程序：输入一个正整数n（1<n<=10）
	再输入n个整数，将这n个整数逆序存放病输出
*/


#include <stdio.h>


int main(void)
{
	/*
	变量n  是用来存放正整数的
	变量i  是用来循环
	数组a[10]   逆序存放从键盘输入的数
	中间变量t  将数组进行交换
	*/
	int n,i,a[10],t;   
	
	printf("请输入变量n的值：");
	scanf("%d",&n);
	
	printf("输入%d个整数:",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);   //输入n个值存放到数组中
	
	
	/*
	将数组中的数据进行逆序排列
	*/
	for(i=0;i<n/2;i++)
	{
		t = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] =t;
	}
	
	//打印数组
	for(i=0; i<n; i++)
	{
		printf("%3d",a[i]);
	}
	
	printf("\n");
	return 0;
}