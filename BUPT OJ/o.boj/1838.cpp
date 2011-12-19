#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(temp==26) printf("A");
		else printf("%c",'A'+temp);
	}
	printf("\n");
	return 0;
}