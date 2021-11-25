/*
冒泡排序：
	将输入的数据，升序排序
*/


#include <stdio.h>

int main(void)
{
	/*
	i\j	用来循环的
	t   中间变量，用来替换数值
	数组a  用来存储数据
	*/
	int i,j,t,a[6];
	
	printf("请输入六个整数：");
	for(i=0; i<6; i++)
	{
		scanf("%d",&a[i]);  
	}
	
	printf("\n");
	/*用冒泡排序的方法  将数组升序排列*/
	for(i=0; i<6; i++)
	{
		for(j=0; j<6-1-i; j++)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	
	printf("冒泡排序之后：\n");
	for(i=0; i<6; i++)
	{
		printf("%3d",a[i]);
	}
	
	printf("\n");
	return 0;
}