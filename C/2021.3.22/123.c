#include<stdio.h>
int main()
{
	char ch;
	long m = 0,n,nx = 0;
	while(ch = getchar(),ch != '\n'){// '\n'
		if(ch >= '0' && ch <= '9'){//i:123 1 * 
            m = m * 10 + (ch - '0');
        }else{
            putchar(ch);
        }
    }
		n = m;
		while(n != 0 && m > 0){	
		    nx = nx * 10 + m % 10;
		    m = m / 10;
		}
	printf("\n%ld  is %ld\n",n,nx);
	
	return 0;
 }