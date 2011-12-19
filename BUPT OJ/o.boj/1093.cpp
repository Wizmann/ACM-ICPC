#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int m;
		scanf("%d",&m);
		int *a=new int[m];
		int *b=new int[m];
		
		memset(b,0,sizeof(int)*m);
		
		for(int j=0;j<m;j++) scanf("%d",&a[j]);
		
		//for(int j=0;j<m;j++) printf("%d ",a[j]);
		//printf("\n");
		
		for(int j=m-1;j>=0;j--)
		{
			int sum=0;
			for(int k=j;k<m;k++)
			{
				if(a[k]>a[j])
				{
					if(b[k]>sum) sum=b[k];
				}
			}
			if(sum==0) b[j]++;
			else b[j]=sum+1;
		}
		//for(int j=0;j<m;j++) printf("%d ",b[j]);
		//printf("\n");
		int max=0;
		for(int j=0;j<m;j++)
		{
			if(b[j]>max) max=b[j];
		}
		printf("%d\n",max);
		free(a);free(b);
	}
	return 0;
}