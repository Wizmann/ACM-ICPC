#include <cstdio>
#include <cstdlib>
#include <cstring>


typedef struct node
{
	int x,y,r,area;
	
	void setnode()
	{
		scanf("%d%d%d",&x,&y,&r);
		area=r*r;
	}
}node;
node array[20];

int n;
char used[20];
int max=-1;

int check(int a,int b)
{
	int t=(array[a].x-array[b].x)*(array[a].x-array[b].x)+(array[a].y-array[b].y)*(array[a].y-array[b].y);
	if(t>(array[a].r+array[b].r)*(array[a].r+array[b].r)) return 1;
	else return 0;
}

void dfs(int k,int area)
{
	if(k==n)
	{
		if(area>max) max=area;
		return;
	}	
	else
	{
		for(int i=0;i<n;i++)
		{
			if(used[i]&&!check(i,k))
			{
				dfs(k+1,area);
				return;
			}
		}
		
		used[k]=1;
		dfs(k+1,area+array[k].area);
		used[k]=0;
		dfs(k+1,area);
	}
}
	

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(array,0,sizeof(array));
		memset(used,0,sizeof(used));
		max=-1;
		scanf("%d",&n);
		for(int i=0;i<n;i++) array[i].setnode();
		dfs(0,0);		
		printf("%d\n",max);
	}
	return 0;
}
		
	
