//Result:wizmann	2289	Accepted	3692K	250MS	G++	1256B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define pb push_back

using namespace std;

int n,m;
vector<int> g[1010];
char visit[1010];
int num[1010];
int match[1010][505];

bool hungary(int pos,int val)
{
	for(int i=0;i<(int)g[pos].size();i++)
	{
		int t=g[pos][i];
		if(!visit[t])
		{
			visit[t]=1;
			if(num[t]<val)
			{
				match[t][++num[t]]=pos;
				return true;
			}

			for(int j=1;j<=val;j++)
			{
				if(hungary(match[t][j],val))
				{
					match[t][j]=pos;
					return true;
				}
			}
		}
	}
	return false;
}
			

int main()
{
	freopen("input.txt","r",stdin);
	char str[30];
	int a;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(m==0) break;
		for(int i=0;i<n;i++) g[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			char c=getchar();
			while(c!='\n')
			{
				scanf("%d",&a);
				g[i].pb(a);
				c=getchar();
			}
		}
		
		int l=0,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			memset(match,-1,sizeof(match));
			memset(num,0,sizeof(num));
			bool flag=true;
			for(int i=0;i<n;i++)
			{
				memset(visit,0,sizeof(visit));
				flag=hungary(i,mid);
				if(!flag) break;
			}
			if(flag) r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
