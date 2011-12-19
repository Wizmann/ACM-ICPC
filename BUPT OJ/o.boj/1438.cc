#include <stdio.h>
#include <stdlib.h>

int cloth[20010];

int cmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}

int* binary(int i,int n,int limit)
{
	int up=i+1;int down=n-1;
	if(cloth[down]+cloth[i]>limit) return NULL;
	else if(cloth[up]+cloth[i]<=limit) return &cloth[up];
	int mid;
	while(up<=down)
	{
		mid=(up+down)/2;
		if(cloth[i]+cloth[mid]<=limit&&cloth[i]+cloth[mid-1]>limit) return &cloth[mid];
		else
		{
			if(cloth[i]+cloth[mid]>limit) up=mid+1;
			else down=mid;
		}
	}
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n,limit;
	scanf("%d%d",&n,&limit);
	while(n&&limit)
	{
		for(int i=0;i<n;i++) scanf("%d",&cloth[i]);
		qsort(cloth,n,sizeof(int),cmp);
		
		int ans=0;
		for(int i=0;i<n-1;i++)
		{
			int *temp=binary(i,n,limit);
			if(temp) ans+=(cloth+n)-temp;
		}
		
		printf("%d\n",ans);
		scanf("%d%d",&n,&limit);
	}
	return 0;
}