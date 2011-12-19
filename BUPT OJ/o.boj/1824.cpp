#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<sqrt(n)+1;i++)
	{
		int res=i;
		res*=(i+1);
		if(res<=n) sum++;
	}
	
	printf("%d\n",sum);
	return 0;
}