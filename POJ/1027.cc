//Result:wizmann	1027	Accepted	260K	375MS	C++	3250B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define N 10
#define M 15
#define mul(x) ((x)*(x))
#define INF 1<<25


const int mx[]={0,1,0,-1};
const int my[]={-1,0,1,0};

struct point
{
	int x,y;
	point(){}
	point(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}
};

char g[N+4][M+4];
int visit[N+2][M+2];
int score();
point q[2048];

inline bool inMap(int x,int y)
{
	if(x>=0 && x<M && y>=0 && y<N) return true;
	else return false;
}

int bfs(int x,int y,int step,char& color,bool kill=false)
{
	q[0]=point(x,y);
	color=g[y][x];
	int res=0;
	int head=0;
	int tail=0;
	while(head<=tail)
	{
		point now=q[head];
		head++;
		if(!visit[now.y][now.x]) res++;
		else continue;
		visit[now.y][now.x]=step;
		for(int i=0;i<4;i++)
		{
			int nx=now.x+mx[i];
			int ny=now.y+my[i];
   

			if(inMap(nx,ny) && !visit[ny][nx] && color==g[ny][nx])
			{
				q[++tail]=point(nx,ny);
			}	
		}
	}
	if(kill)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(visit[i][j]==step) g[i][j]='X';
			}
		}
	}
	return res;
}

void kill(int x,int y,int step)
{
	char color;
	memset(visit,0,sizeof(visit));
	bfs(x,y,step,color,true);
	//printG();
	for(int j=0;j<M;j++)
	{
		for(int i=N;i>0;i--)
		{
			for(int k=N-1;k>=0;k--)
			{
				if(g[k][j]=='X')
				{
					swap(g[k+1][j],g[k][j]);
				}
			}
		}
	}
	for(int k=0;k<N;k++)
	{
		for(int j=0;j<M-1;j++)
		{
			int sum=0;
			for(int i=0;i<N;i++)
			{
				if(g[i][j]=='X') sum++;
			}
			if(sum==N)
			{
				//print("SUM:"<<j);
				for(int i=0;i<N;i++)
				{
					swap(g[i][j],g[i][j+1]);
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	input(T);
	int cas=1;
	while(T--)
	{
		printf("Game %d:\n\n",cas++);

		for(int j=0;j<M+2;j++) g[N][j]='X';

		for(int i=N-1;i>=0;i--)
		{
			scanf("%s",g[i]);
			g[i][M]='X';
		}
		int score=0;
		char color;
		char finalColor;
		int step=0;
		int killNum=0;
		while(1)
		{
			//print(step);
			//printG();
			step++;
			memset(visit,0,sizeof(visit));
			point stPnt=point(INF,INF);
			int maxNum=-1;
			for(int j=0;j<M;j++)
			{
				for(int i=0;i<N;i++)
				{
					if(!visit[i][j] && g[i][j]!='X')
					{
						int num=bfs(j,i,step,color);
						//print(num);
						if(num>maxNum)
						{
							stPnt=point(j,i);
							maxNum=num;
							finalColor=color;
						}
						else if(num==maxNum)
						{
							if(j<stPnt.x)
							{
								stPnt=point(j,i);
								finalColor=color;
							}
							else if(j==stPnt.x && i<stPnt.y)
							{
								stPnt=point(j,i);
								finalColor=color;
							}
						}
					}
				}
			}
			//print(maxNum);
			if(maxNum<=1) break;
			else killNum+=maxNum;
			score+=mul(maxNum-2);
			//print(stPnt.y<<' '<<stPnt.x);
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",step,stPnt.y+1,stPnt.x+1,maxNum,finalColor,mul(maxNum-2));
			kill(stPnt.x,stPnt.y,step);
			
		}
		if(M*N-killNum==0) score+=1000;
		
		printf("Final score: %d, with %d balls remaining.\n\n",score,M*N-killNum);
	}
	return 0;
}
