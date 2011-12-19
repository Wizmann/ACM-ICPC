#include <cstdio>
#include <cstdlib>
#include <cstring>

char g[510][510];
char used[510];
int link[510];

int findpath(int size,int pos)
{
	for(int i=1;i<=size;i++)
	{
		if(!used[i]&&g[pos][i])
		{
			used[i]=1;
			if(link[i]==-1||findpath(size,link[i]))
			{
				link[i]=pos;
				return true;
			}
		}
	}
	return false;
}
			

int max_match(int size)
{
	int ans=0;
	for(int i=1;i<=size;i++)
	{
		memset(used,0,sizeof(used));
		if(findpath(size,i)) ans++;
	}
	return ans;
}	

int main()
{
	freopen("input.txt","r",stdin);
	
	int size,num;
	int a,b;
	scanf("%d%d",&size,&num);
	memset(link,-1,sizeof(link));
	for(int i=0;i<num;i++)
	{
		scanf("%d%d",&a,&b);
		g[a][b]=1;
	}
	printf("%d\n",max_match(size));
	return 0;
}
