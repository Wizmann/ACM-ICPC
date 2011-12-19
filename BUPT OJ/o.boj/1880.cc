#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define N 50000

int digit[N];

void init()
{
	int d=1;
	for(int i=1;i<N;i++)
	{
		digit[i]=digit[i-1]+d;
		if(i==9||i==99||i==999||i==9999) d++;
	}
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	init();
	int n,temp;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&temp);
		int i;
		for(i=1;i<N;i++)
		{
			if(digit[i]>=temp) break;
			else temp-=digit[i];
		}
		
		int mod=0;
		if(temp)
		{
			for(i=1;i<N;i++) if(digit[i]>=temp) break;
			mod=temp-digit[i-1]-1;
		}
		
		
		char print[10];
		sprintf(print,"%d",i);
		printf("%c\n",print[mod]);
	}
	return 0;
}