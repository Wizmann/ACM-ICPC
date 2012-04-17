#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 12
#define elif else if
#define INF 1<<25

struct point
{
	int x,y;
	point(){x=y=-1;}
	point(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}
	friend bool operator == (const point& a,const point& b)
	{
		return a.x==b.x && a.y==b.y;
	}
};

char g[SIZE][SIZE];
point piece[SIZE];
int m,n;
int ind;
const int mx[]={0,1,0,-1};
const int my[]={-1,0,1,0};


int makeStatus(const point& pawn,const point& mir,const point& knight,int knightDir,int getMem)
{
	int res=0;
	res|=getMem;res<<=5;
	res|=knight.x;res<<=4;
	res|=knight.y;res<<=4;
	res|=knightDir;res<<=2;
	res|=mir.x;res<<=4;
	res|=mir.y;res<<=4;
	res|=pawn.x;res<<=4;
	res|=pawn.y;
	return res;
}

bool inMap(const point& p)
{
	if(p.x>=0 && p.x<m && p.y>=0 && p.y<n)
	{
		if(g[p.y][p.x]=='R') return false;
		else return true;
	}
	return false;
}

struct node
{
	int status;
	int step;

	node(){}
	node(int i_status,int i_step)
	{
		status=i_status;
		step=i_step;
	}
	bool OK()
	{
		int st=status;
		int res=status>>26;
		if(res==(1<<ind)-1)
		{
			int a,b;
			a=b=(1<<5)-1;
			b&=st;st>>=4;
			a&=st;st>>=4;
			point pawn=point(a,b);
			a=b=(1<<5)-1;
			b&=st;st>>=4;
			a&=st;st>>=4;
			point mirPawn=point(a,b);
			
			if(g[pawn.y][pawn.x]=='E' && g[mirPawn.y][mirPawn.x]=='E') return true;
		}
		return false;
	}
	bool move(int dir)
	{
		step++;
		int a,b;
		a=b=(1<<5)-1;
		b&=status;status>>=4;
		a&=status;status>>=4;
		point pawn=point(a,b);
		
		a=b=(1<<5)-1;
		b&=status;status>>=4;
		a&=status;status>>=4;
		point mirPawn=point(a,b);

		a=(1<<3)-1;
		a&=status;
		int knightDir=a;

		a=b=(1<<5)-1;
		b&=status;status>>=4;
		a&=status;status>>=4;
		point knight=point(a,b);

		int gain=status;

		point nextPawn=pawn;
		nextPawn.x+=mx[dir];
		nextPawn.y+=my[dir];
		if(inMap(nextPawn))
		{
			if(nextPawn==knight) return false;
			pawn=nextPawn;
		}
		else return false;

		point nextMirPawn=mirPawn;
		nextMirPawn.x+=mx[dir];
		nextMirPawn.y+=my[dir];
		if(inMap(nextMirPawn))
		{
			if(nextMirPawn==knight) return false;
			mirPawn=nextMirPawn;
		}
		point nextKnight;
		nextKnight.x+=mx[knightDir];
		nextKnight.y+=my[knightDir];
		if(inMap(nextKnight)) knight=nextKnight;
		else knightDir=(knightDir+2)%4;


		if(knight==pawn || knight==mirPawn) return false;
		for(int i=0;i<ind;i++)
		{
			if(pawn==piece[i] || mirPawn==piece[i])
			{
				gain|=(1<<i);
			}
		}

		status=makeStatus(pawn,mirPawn,knight,knightDir,gain);
		return true;
	}
};


inline int char2Dir(char x)
{
	switch(x)
	{
		case 'N':return 0;break;
		case 'E':return 1;break;
		case 'S':return 2;break;
		case 'W':return 3;break;
	}
	return -1;
}


int bfs(int i_status)
{
	queue<node> q;
	int ans=INF;
	set<int> hash;
	q.push(node(i_status,0));
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		if(hash.find(now.status)!=hash.end()) continue;
		else hash.insert(now.status);
		if(now.OK())
		{
			ans=min(ans,now.step);
			break;
		}
		for(int i=0;i<4;i++)
		{
			node next=now;
			if(now.move(i))
			{
				q.push(now);
			}
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	char cmd[4];
	while(input(n>>m))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",g[i]);
		}
		scanf("%s",cmd);
		ind=0;
		point pawn,mirPawn;
		point knight;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(g[i][j]=='A') pawn=point(j,i);
				elif(g[i][j]=='B') mirPawn=point(j,i);
				elif(g[i][j]=='K') knight=point(j,i);
				elif(g[i][j]=='M') piece[ind++]=point(j,i);

				if(g[i][j]!='E' || g[i][j]!='*' || g[i][j]=='R')
				{
					g[i][j]='*';
				}
			}
		}
		int status=makeStatus(pawn,mirPawn,knight,char2Dir(*cmd),0);
		print(bfs(status));
	}
	return 0;
}

		
