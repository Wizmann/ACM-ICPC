#include <cstdio>
#include <cstring>
#include <cstdlib>

int queue[1010];
char pos[1010];

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&queue[i]);
	int res=0;
	int max=-1;
	for(int i=1;i<=n;i++)
	{
		int temp=i;
		int ans=0;
		memset(pos,0,sizeof(pos));
		while(!pos[temp])
		{
			pos[temp]=1;
			temp=queue[temp];
			ans++;
		}
		if(ans>max)
		{
			max=ans;
			res=i;
		}
	}
	printf("%d\n",res);
	return 0;
}
