#include <cstdio>
#include <cstdlib>
#include <cstring>

int ex[100100];

int n,t;

int search(int mid)
{
	int ans=0;
	int tp=0;
	for(int i=0;i<n;i++)
	{
		ans+=ex[i];
		if(ans>=mid)
		{
			if(ans>mid) i--;
			ans=0;tp++;
			if(tp>t) break;
		}
	}
	if(tp>=t) return 0;
	else return 1;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&t);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ex[i]);
		sum+=ex[i];
	}
	int high=sum;
	int low=sum/n;
	int mid;
	while(high>=low)
	{
		mid=(high+low)/2;
		if(search(mid)==0) low=mid+1;
		else high=mid-1;
	}
	printf("%d\n",low);
	
	return 0;
}
