#include <stdio.h>

int J[14]={2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};


int main()
{
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		printf("%d\n",J[n-1]);
		scanf("%d",&n);
	}
	return 0;
}