#include <cstdio>
#include <cstdlib>
#include <cstring>

int lnum,rnum;
int max,n;
int g[21][21];
int left[21],right[21];
void dfs(int pos)
{
	if(pos==n)
	{
		int sum=0;
		for(int i=0;i<lnum;i++)
		{
			for(int j=0;j<rnum;j++) sum+=g[left[i]][right[j]];
		}
		if(sum>max) max=sum;
	}
	else
	{
		left[lnum]=pos;
		lnum++;
		dfs(pos+1);
		lnum--;
		
		right[rnum]=pos;
		rnum++;
		dfs(pos+1);
		rnum--;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) scanf("%d",&g[i][j]);
	}
	
	max=0;
	lnum=rnum=0;
	dfs(0);
	printf("%d\n",max);
	return 0;
}
