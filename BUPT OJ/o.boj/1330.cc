#include <cstdio>
#include <rope.h>

int array[5000000];
int t=1;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case %d: ",t++);
		for(int i=0;i<n;i++) scanf("%d",&array[i]);
		if(n%2)
		{
			nth_element(array,array+n/2,array+n);
			printf("%d\n",array[n/2]);
		}
		else
		{
			nth_element(array,array+n/2,array+n);
			nth_element(array,array+n/2+1,array+n);
			if(array[n/2]==array[n/2+1]) printf("%d\n",array[n/2]);
			else
			{
				nth_element(array,array+n/2-1,array+n);
				printf("%d\n",array[n/2-1]);
			}
		}
		printf("\n");
	}
	return 0;
}