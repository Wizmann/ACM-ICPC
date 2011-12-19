#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char musik[10050];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	int cas=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		memset(musik,0,sizeof(musik));
		int N,Q;
		scanf("%d%d",&N,&Q);
		char flag=1;
		char *p=musik;
		for(int k=0;k<N;k++)
		{
			int m;
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				*(p++)=flag;
			}
			flag++;
		}
		printf("Case #%d:\n",cas++);
		for(int k=0;k<Q;k++)
		{
			int q;
			scanf("%d",&q);
			printf("%d\n",musik[q]);
		}
	}
	return 0;
}