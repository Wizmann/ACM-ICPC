#include <cstdio>
#include <cstdlib>
#include <cstring>

int rmDigit(int pad,int n)
{
	if(n==0) return 1;
	else if(n==1) return pad%10;
	else
	{
		int temp=rmDigit(pad,n/2)%10;
		if(n%2) return ((temp*temp)*(pad%10))%10;
		else return (temp*temp)%10;
	}
}
			

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",rmDigit(n,n));
	}
	return 0;
}
