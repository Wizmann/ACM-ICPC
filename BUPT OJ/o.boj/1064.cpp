#include <stdio.h>
#include <stdlib.h>

#define LOCAL

int GCD(int a,int b)
{
	if(a>=b)
	{
		if(a%b==0) return b;
		else return GCD(b,a%b);
	}
	else return GCD(b,a);
}

int LCM(int a,int b)
{
	return (a*b)/GCD(a,b);
}

int* creat(int n)
{
	int *ret=(int*)malloc(sizeof(int)*n);
	return ret;  
}


int main()
{
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	int *array=creat(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	int MAX=array[0];
	for(int i=1;i<n;i++)
	{
			printf("%d/%d\n",LCM(MAX,array[i])/array[i],LCM(MAX,array[i])/MAX);
	}
	return 0;
}