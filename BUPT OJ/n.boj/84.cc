#include <cstdio>
#include <cstdlib>
#include <cstring>

int g[15][15];
long long ans=0;

const int mx[4]={1,-1, 0, 0};
const int my[4]={0, 0,-1, 1};

int tx,ty,l;

void dfs(int x,int y,int k)
{
	if(k==0)
	{
		ans++;
		return;
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			int nx=x,ny=y;
			nx+=mx[i];ny+=my[i];
			if(nx>=0&&nx<tx&&ny>=0&&ny<ty&&!g[ny][nx])
			{
				g[ny][nx]=1;
				dfs(nx,ny,k-1);
				g[ny][nx]=0;
			}
		}
	}
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	while(scanf("%d%d%d",&tx,&ty,&l)!=EOF)
	{
		long long sum=0;
		for(int i=0;i<ty;i++)
		{
			for(int j=0;j<tx;j++)
			{
				memset(g,0,sizeof(g));
				ans=0;
				g[i][j]=1;
				dfs(j,i,l-1);
				sum+=ans;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
				
