#include <cstdio>
#include <cstring>
#include <cstdlib>

char mat[42][12];
int mark[42][12];
int ans[420][420];
int match[420];
int h,w;
char used[420];

const int mx[]={1,-1,0,0};
const int my[]={0,0,-1,1};

bool dfs(int p)
{
	int t;
	for(int i=1;i<=h*w;i++)
	{
		if(ans[p][i]&&!used[i])
		{
			used[i]=1;
			t=match[i];
			match[i]=p;
			if(t==0||dfs(t)) return true;
			match[i]=t;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t,cnt;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		memset(mat,0,sizeof(mat));
		memset(ans,0,sizeof(ans));
		memset(mark,0,sizeof(mark));
		memset(match,0,sizeof(match));
		scanf("%d%d",&h,&w);
		for(int i=0;i<h;i++)
		{
			scanf("%s",mat[i]);
			for(int j=0;j<w;j++)
			{
				if(mat[i][j]=='*') mark[i][j]=++cnt;
			}
		}
		
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(mark[i][j])
				{
					for(int k=0;k<4;k++)
					{
						if(i+mx[k]>=0&&i+mx[k]<h&&j+my[k]>=0&&j+my[k]<w)
						{
							if(mark[i+mx[k]][j+my[k]]) ans [mark[i][j]] [mark[i+mx[k]][j+my[k]]] =1;
						}
					}
				}
			}
		}
		
		int res=0;
		for(int i=1;i<=cnt;i++)
		{
			memset(used,0,sizeof(used));
			if(dfs(i)) res++;
		}
		
		printf("%d\n",cnt-res/2);
	}
	return 0;
}
		
		
