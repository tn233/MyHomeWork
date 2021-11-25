#include <stdio.h>
#include <string.h>

int main(void)
{
	int a[6]={0,1,2,3,4,5};
	int i;
	for(i=0;i<6;i++)
	{
		printf("a[%d]:%d\n",i,a[i]);
	}
	
	printf("\n");
	//柔性数组
	int b[] = {123,4897,1354,54};
	for(i=0;i<sizeof(b)/4;i++)
	{
		printf("b[%d]:%d\n",i,b[i]);
	}
	
	printf("定义一个静态数组：\n");
	//定义一个静态数组：
	static int c[6];
	for(i=0;i<6;i++)
	{
		printf("c[%d]:%d\n",i,c[i]);
	}
	
	printf("定义一个动态数组：\n");
	//定义一个动态数组：
	int d[6];
	for(i=0;i<6;i++)
	{
		printf("d[%d]:%d\n",i,d[i]);
	}
	
	//只给数组前几个元素赋值
	printf("只给数组前几个元素赋值\n");
	int e[6] = {0,1,2};   //e[0] 0  e[1] 1  e[2] 2 
	for(i=0;i<6;i++)
	{
		printf("e[%d]:%d\n",i,e[i]);
	}
		
	//将数组F全部赋值为0
	printf("将数组F全部赋值为0\n");
	int f[6] = {0};
	for(i=0;i<6;i++)
	{
		printf("f[%d]:%d\n",i,f[i]);
	}
	
	/*printf("初始值的个数大于数组的长度\n");
	int j[6] = {0,1,2,3,4,5,6};
	for(i=0;i<6;i++)
	{
		printf("j[%d]:%d\n",i,j[i]);
	}*/
	
	int test=10, num=200,cc;
	int h[3] = {test,num,cc};
	for(i=0;i<3;i++)
	{
		printf("h[%d]:%d\n",i,h[i]);
	}
	
	
	
	return 0;
}