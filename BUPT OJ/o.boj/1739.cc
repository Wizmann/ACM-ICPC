#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[100000];
int len;

int findmin()
{
	int i=0,j=1,k=0,t;
	while(i<len&&j<len&&k<len)
	{
		t=str[(i+k)%len]-str[(j+k)%len];
		if(!t) k++;
		else
		{
			if(t<0) j+=k+1;
			else i+=k+1;
			
			if(i==j) j++;
			k=0;
		}
	}
	return j>i?i:j;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		len=strlen(str);
		int cut=findmin();
		for(int i=cut;i<cut+len;i++) printf("%c",str[i%len]);
		printf("\n");
	}
	return 0;
}