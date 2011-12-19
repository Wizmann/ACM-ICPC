#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int array[100100];

int main()
{
	
	//freopen("input.txt","r",stdin);
	
	int n,i;
	long long res;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&array[i]);
		res=1;
		while(--n) res=(array[n]*res+1)%9;		
		res*=array[0];
		res%=9;
		printf("%lld\n",res==0?9:res);
	}
	return 0;
}