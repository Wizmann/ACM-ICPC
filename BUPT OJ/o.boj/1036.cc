#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 200000000000000000LL
#define eps 1e-8

#define pb push_back

long long g[1010][1010];
long long min[1010];
long long pre[1010];
char used[1010];
std::vector<int> table[1010];
long long ans,tres=0,res;
int n;

void prim()
{
	for(int i=1;i<=n;i++)
	{
		min[i]=g[1][i];
		pre[i]=1;
	}
	used[1]=1;
	
	int next;
	long long len=INF;
	for(int i=2;i<=n;i++)
	{
		len=INF;
		for(int j=1;j<=n;j++)
		{
			if(min[j]<len&&!used[j])
			{
				len=min[j];
				next=j;
			}
		}
		table[next].pb(pre[next]);
		table[pre[next]].pb(next);
		used[next]=1;
		//printf("NEXT=%d LEN=%d\n",next,len);
		ans+=len;
		
		for(int j=1;j<=n;j++)
		{
			if(min[j]>g[next][j])
			{
				min[j]=g[next][j];
				pre[j]=next;
			}
		}
	}
}

void dfs(int pos,long long dis)
{
	if(tres>=res) return;
	
	int t,m;
	tres+=dis;
	m=table[pos].size();
	for(int i=0;i<m;i++)
	{
		t=table[pos][i];
		if(!used[t])
		{
			//printf("%d %d\n",pos,t);
			used[t]=1;
			dfs(t,dis+g[t][pos]);
		}
	}	
}

void print(long long A)
{
    
    if(A%10!=0) 
        printf("%.2lf\n",A/100.0);
    else if((A/10)%10!=0)
        printf("%.1lf\n",A/100.0);
    else 
        printf("%.0lf\n",A/100.0);
}

			

int main()
{
	freopen("input.txt","r",stdin);
	int t,pos;
	double input;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;res=INF;pos=-1;
		scanf("%d",&n);
		for(int i=1;i<=n+5;i++) table[i].clear();
		memset(min,0,sizeof(min));
		memset(g,0,sizeof(g));
		memset(pre,0,sizeof(pre));
		memset(used,0,sizeof(used));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%lf",&input);
				g[i][j]=(input+eps)*100;
				if(!g[i][j]) g[i][j]=INF;
			}
		}
		
		prim();
		print(ans);
		
		for(int i=1;i<=n;i++)
		{
			tres=0;
			memset(used,0,sizeof(used));
			used[i]=1;
			dfs(i,0);
			//printf("%d %lld\n",i,tres);
			if(tres<res)
			{
				res=tres;
				pos=i;
			}
		}
		printf("%d ",pos);
		print(res*2);
		printf("\n");
	}
	return 0;
}
		
