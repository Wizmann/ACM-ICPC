#include <stdio.h>

int main()
{
	//freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n!=0)
	{	int mm=0;
		for(int i=0;i<n;i++)
		{			
			int a,sex,b;
			scanf("%d%d%d",&a,&sex,&b);
			if(sex!=1) mm++;
		}
		printf("%d\n",mm);
		scanf("%d",&n);
	}
	return 0;
}