#include <stdio.h>

int main(void)
{
	
	/*
	变量i  循环
	数组a  ----存放五个学生的成绩
	max    用来存放数组中的最大值
	min    用来存放数组中的最小值
	aver   用来存放数组中的平均值
	t      作为中间变量
	*/
	int i,a[5],max,min,t;
	float aver;
	
	printf("需要输入5为学生的成绩\n");
	for(i=0;i<5;i++)
	{
		printf("请输入第%d位学生的成绩:",i);
		scanf("%d",&a[i]);
	}
	
	/*
	首先将数组中的第一个值赋值给max和min
	*/
	max = a[0];
	min = a[0];
	
	for(i=0;i<5;i++)
	{
		if(max < a[i])
		{
			max = a[i];
		}
		
		if(min > a[i])
		{
			min = a[i];
		}
		
		aver +=a[i];
	}
	
	aver = aver/5.0;
	
	printf("成绩最大值：%d\n",max);
	printf("成绩最小值：%d\n",min);
	printf("成绩的平均值：%.2f\n",aver);
	
	
	return 0;
}