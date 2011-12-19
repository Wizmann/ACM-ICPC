#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	char number[40];
	char *p=number;
	while(scanf("%s",number)!=EOF)
	{
		p=number;
		bool flag= *p=='0'? true:false;
		int E=0;
		p++;
		for(int i=7;i>=0;i--)
		{
			E+=(*(p++)-'0')*(int)pow(2,i);
		}
		E-=127;
		double dot=1;
		for(int i=0;i<23;i++)
		{
			dot+=(*(p++)-'0')*pow(2,-1-i);
		}
		if(flag==false) printf("-");
		printf("%.2lf\n",(double)pow(2,E)*dot);
	}
	return 0;
}