/*
直接法排序：
	从键盘中输入10个值，用直接法升序排序
*/

#include <stdio.h>

int main(void)
{
	int i,j,t,a[10],k;
	
	printf("请输入10个整数：");
	for(i=0; i<10; i++)
	{
		printf("%d",&a[i]);
	}
	printf("\n");
	
	
	for(i=0; i<9; i++)
	{
		k = i;
		for(j=i+1; j<10; j++)
		{
			if(a[k] > a[j])
			{
				k = j;
			}	
		}
		
		if(i!=k)
		{
			t = a[k];
			a[k] = a[i];
			a[i] = t;
			
		}
	}
	
	for(i=0; i<10; i++)
	{
		printf("%3d",a[i]);
	}

	return 0;
}