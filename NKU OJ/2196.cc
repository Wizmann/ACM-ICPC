#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define ALPHA 30
#define INF 1<<25

const int mx[]={1,-1,0,0};
const int my[]={0,0,1,-1};

struct point
{
	int x,y,step;
	point(){}
	point(int i_x,int i_y,int i_step)
	{
		x=i_x;y=i_y;
		step=i_step;
	}
	
	friend bool operator == (const point& p1,const point& p2)
	{
		return p1.x==p2.x&&p1.y==p2.y;
	}
};

char g[SIZE][SIZE];
int cnc[ALPHA][ALPHA];
int n,m,k;
point START,END;
int step[SIZE][SIZE];
point alpha[ALPHA];

inline bool isalpha(char x)
{
	if(x>='A' && x<='Z') return true;
	else return false;
}

int bfs()
{
	queue<point> q;
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++) step[i][j]=INF;
	}
	q.push(START);
	while(!q.empty())
	{
		point now=q.front();
		q.pop();
		int nx=now.x;
		int ny=now.y;
		int ns=now.step;
		
		//cout<<"X,Y,S: "<<nx<<' '<<ny<<' '<<ns<<endl;
		
		if(step[ny][nx]>ns) step[ny][nx]=ns;
		else continue;
		
		if(now==END) continue;
		
		for(int i=0;i<4;i++)
		{
			int tx=nx+mx[i];
			int ty=ny+my[i];
			int ts=ns+1;
			
			if(g[ty][tx]=='#' || step[ty][tx]<=ts) continue;
			else if(tx>=0 && tx<m && ty>=0 && ty<n)
			{
				q.push(point(tx,ty,ts));
			}
		}
		
		if(isalpha(g[ny][nx]))
		{
			int na=g[ny][nx]-'A';
			for(int i=0;i<k;i++)
			{
				if(cnc[na][i])
				{
					point next=point(alpha[i].x,alpha[i].y,ns+1);
					if(step[next.y][next.x]<=next.step) continue;
					else q.push(next);
				}
			}
		}
	}
	return step[END.x][END.y]>=INF?-1:step[END.x][END.y];
}
			
		
		

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n>>m>>k))
	{
		memset(cnc,0,sizeof(cnc));
		for(int i=0;i<n;i++)
		{
			scanf("%s",g[i]);
			for(int j=0;g[i][j];j++)
			{
				if(g[i][j]>='A' && g[i][j]<='Z')
				{
					alpha[int(g[i][j]-'A')]=point(j,i,0);
				}
			}
		}
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				scanf("%d",&cnc[i][j]);
			}
		}
		int a,b;
		scanf("%d%d",&a,&b);
		START=point(a-1,b-1,0);
		scanf("%d%d",&a,&b);
		END=point(a-1,b-1,0);
		print(bfs());
	}
	return 0;
}

