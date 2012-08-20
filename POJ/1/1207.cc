#include <cstdio>
#include <cstdlib>
#include <cstring>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

int save[10020];

int cal(int x)
{
	int res=1;
	while(x!=1)
	{
		if(x%2) x=3*x+1;
		else x/=2;
		res++;
	}
	return res;
}

int main()
{
	int a,b;
	memset(save,-1,sizeof(save));
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d %d ",a,b);
		int r=max(a,b),l=min(a,b);
		int ans=-1;
		for(;l<=r;l++)
		{
			if(save[l]==-1) save[l]=cal(l);
			if(ans<save[l]) ans=save[l];
		}
		printf("%d\n",ans);
	}
	return 0;
}