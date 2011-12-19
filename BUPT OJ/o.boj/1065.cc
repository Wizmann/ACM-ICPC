#include <cstdio>

const int mx[4]={1,0,-1,0};
const int my[4]={0,1,0,-1};

char alpha[30];
char g[30][30];

int y,x;
int movx,movy;

int dfs(int ty,int tx)
{
	int res=0,t;
	alpha[g[ty][tx]-'A']=1;
	for(int i=0;i<4;i++)
	{
		movx=tx+mx[i];movy=ty+my[i];
		if(movx>=0&&movx<x&&movy>=0&&movy<y&&!alpha[g[movy][movx]-'A'])
		{
			t=dfs(movy,movx);
			if(t>res) res=t;
		}
	}
	alpha[g[ty][tx]-'A']=0;
	return res+1;
}		

int main()
{
	scanf("%d%d",&y,&x);
	for(int i=0;i<y;i++) scanf("%s",g[i]);
	int ans=dfs(0,0);	
	printf("%d\n",ans);
	return 0;
}
			
