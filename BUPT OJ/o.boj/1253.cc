#include <cstdio>
#include <cstdlib>
#include <cstring>

char ans[510][510];
char used[510];
int match[510];
int n;

bool dfs(int p)
{
	int t;
	for(int i=1;i<=n;i++)
	{
		if(ans[p][i]&&!used[i])
		{
			t=match[i];
			used[i]=1;
			match[i]=p;
			if(t==-1||dfs(t))
			{
				return true;
			}
			match[i]=t;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t,input,res;
	while(scanf("%d",&n)!=EOF)
	{
		res=0;
		n/=2;
		memset(ans,0,sizeof(ans));
		memset(match,-1,sizeof(match));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d",&input);
				ans[i][input]=1;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			memset(used,0,sizeof(used));
			if(dfs(i)) res++;
		}
		
		printf("%d\n",res*2);
	}
	return 0;
}
