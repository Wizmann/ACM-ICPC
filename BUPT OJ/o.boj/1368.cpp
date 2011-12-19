#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int prim(int n)
{
	if(n!=2&&n%2==0) return 0;
	if(n!=3&&n%3==0) return 0;
	for(int i=3;i*i<=n;i+=2)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	while(n)
	{
		int left=n-1,right=n+1;
		
		if(prim(n)) printf("0\n");
		else
		{
			while(!prim(left)) left--;
			while(!prim(right)) right++;
			
			printf("%d\n",right-left);
		}
		
		
		scanf("%d",&n);
	}
	return 0;
}