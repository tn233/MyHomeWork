/*题目：输出斐波拉契数列的前二十项
	特点：第一个值  ：1	
		  第二个值  ：1
		  之后的值：等于前两个数之间的和



*/
#include <stdio.h>

int main(void)
{
	/*
	数组名f的作用：用来存储斐波拉契数列的前二十项的值
	*/
	int f[21],i;   
	f[1]=1;
	f[2]=1;
	
	for(i=3; i<21; i++)
	{
		f[i] = f[i-1]+f[i-2];
	}
	
	for(i=1; i<21; i++)
	{
		printf("%3d\n",f[i]);
	}
	
	
	printf("\n");
	return 0;
}
