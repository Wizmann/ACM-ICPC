#include <cstdio>
#include <cstdlib>
#include <cstring>

int ans[155];

int joseph(int n,int m)
{
	int s=0;
	for(int i=2;i<n;i++) s=(s+m)%i;
	return s+2;
}

int main()
{
	for(int i=3;i<=150;i++)
	{
		for(int j=2;/*Nothing*/;j++)
		{
			if(joseph(i,j)==2)
			{
				ans[i]=j;
				break;
			}
		}
	}
	
	int n;
	while(scanf("%d",&n),n) printf("%d\n",ans[n]);
	return 0;
}
