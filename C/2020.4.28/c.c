#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *ch = (char*)malloc(100);
	int n = 0;//n为出现的次数
    int i = 0,b = 0;
	//ch = getchar();
	while((ch[b++]=getchar())!='\n')
	{
      if(b>=2){
        if(ch[i]=='e'&&ch[i+1]=='i'){
          n++;
        }
        i++;
      }
      
	}

	printf("ei出现的次数为%d\n", n);
}