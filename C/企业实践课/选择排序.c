/*
选择法排序
	从键盘输入10个值，要求按升序排序，输出排序的结果
*/

#include <stdio.h>

int main(void)
{
	/*定义数组a  数组的长度为10  
	变量	i		用作循环
	变量 	j		用作循环
	变量	t	   中间变量，用作替换
	*/
	int i,j,t,a[10];
	printf("请输入10个整数：");
	
	for(i=0; i<10; i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("\n");
	
	printf("排序之前：");
	for(i=0; i<10; i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
	for(i=0; i<9; i++)
	{
		for(j=i+1;j<10;j++)
		{
			/*交换数值的位置*/
			if(a[i] < a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		
	}
	
	printf("排序之后：");
	for(i=0; i<10; i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
	return 0;
}