#include <stdio.h>
#include <math.h>

int is_prim(int n)
{
	for(int i=sqrt(n);i>1;i++)
	{
		if(n%i==0) return i;
	}
	return -1;
}


int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	int max=0;
	int ret;
	for(int i=0;i<n;i++)
	{		
		int temp;
		scanf("%d",&temp);
		int X=is_prim(temp);
		if(X==-1) X=temp;
		printf("%d -- %d\n",temp,X);
		if(X>max)
		{
			ret=temp;
			max=X;
		}
	}
	printf("%d\n",ret);
	return 0;
}

