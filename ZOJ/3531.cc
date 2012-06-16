#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 12
#define elif else if
#define INF 1<<30
#define MOD 100000007

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
	
	friend bool operator != (const point& a,const point& b)
	{
		return !(a.x==b.x && a.y==b.y);
	}
};

char g[SIZE][SIZE];
point piece[SIZE];
int m,n,ind;
const int mx[]={0,1,0,-1};
const int my[]={-1,0,1,0};
bitset<MOD> hash;
//TLE:
//Hash is faster than Set


int makeStatus(const point& pawn,const point& mir,const point& knight,int knightDir,int getMem)
{
	int res=0;
	res|=getMem;
	res<<=4;res|=knight.x;
	res<<=4;res|=knight.y;
	res<<=2;res|=knightDir;
	res<<=4;res|=mir.x;
	res<<=4;res|=mir.y;
	res<<=4;res|=pawn.x;
	res<<=4;res|=pawn.y;
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
	unsigned int status;
	int step;

	node(){}
	node(int i_status,int i_step)
	{
		status=i_status;
		step=i_step;
	}
	int OK()//Drei Status caused WA
	{
		int st=status;
		int res=status>>26;
		int a,b;
		a=b=(1<<4)-1;
		b&=st;st>>=4;
		a&=st;st>>=4;
		point pawn=point(a,b);
		a=b=(1<<4)-1;
		b&=st;st>>=4;
		a&=st;st>>=4;
		point mirPawn=point(a,b);
		int ok=(1<<ind)-1;
		if(ind==0) ok=0;
		if(g[pawn.y][pawn.x]=='E' && g[mirPawn.y][mirPawn.x]=='E')
		{
			if(res==ok) return true;
			else return -1;
		}
		else return false;
	}
	bool move(int dir)
	{
		step++;
		int a,b;
		a=b=(1<<4)-1;
		b&=status;status>>=4;
		a&=status;status>>=4;
		point pawn=point(a,b);
		
		a=b=(1<<4)-1;
		b&=status;status>>=4;
		a&=status;status>>=4;
		point mirPawn=point(a,b);

		a=(1<<2)-1;
		a&=status;
		int knightDir=a;
		status>>=2;

		a=b=(1<<4)-1;
		b&=status;status>>=4;
		a&=status;status>>=4;
		point knight=point(a,b);

		int gain=status;

		point nextPawn=pawn;
		nextPawn.x+=mx[dir];
		nextPawn.y+=my[dir];
		if(inMap(nextPawn))
		{
			if(nextPawn==knight || nextPawn==mirPawn) return false;
			pawn=nextPawn;
		}
		else return false;

		point nextMirPawn=mirPawn;
		nextMirPawn.x+=mx[(dir+2)%4];
		nextMirPawn.y+=my[(dir+2)%4];
		if(inMap(nextMirPawn) && nextMirPawn!=knight && nextMirPawn!=pawn)
		{
			mirPawn=nextMirPawn;
		}
		point nextKnight=knight;
		nextKnight.x+=mx[knightDir];
		nextKnight.y+=my[knightDir];
		if(inMap(nextKnight)) knight=nextKnight;
		else knightDir=(knightDir+2)%4;

		if(g[pawn.y][pawn.x]=='E' && g[mirPawn.y][mirPawn.x]=='E')
		{
			status=makeStatus(pawn,mirPawn,knight,knightDir,gain);
		}
		else
		{
			if(knight==pawn || knight==mirPawn) return false;
			for(int i=0;i<ind;i++)
			{
				if(pawn==piece[i]) gain|=(1<<i);//Only Alice can attach to the Memory Piece WA
			}
			status=makeStatus(pawn,mirPawn,knight,knightDir,gain);
		}
		return true;
	}
	
	void printinfo()
	{
		char tg[SIZE][SIZE];
		memcpy(tg,g,sizeof(g));
		print("INFO:"<<step);
		int st=status;
		int a,b;
		a=b=(1<<4)-1;
		b&=status;status>>=4;
		a&=status;status>>=4;
		point pawn=point(a,b);
		tg[b][a]='A';
		
		a=b=(1<<4)-1;
		b&=status;status>>=4;
		a&=status;status>>=4;
		point mirPawn=point(a,b);
		tg[b][a]='B';

		a=(1<<2)-1;
		a&=status;
		int knightDir=a;
		status>>=2;
		printf("KnightDir:%d\n",knightDir);

		a=b=(1<<4)-1;
		b&=status;status>>=4;
		a&=status;status>>=4;
		point knight=point(a,b);
		tg[b][a]='K';
		int gain=status;
		printf("Gain:%d\n",gain);
		status=st;
		for(int i=0;i<ind;i++)
		{

			if(!(gain & (1<<i)))
			{
				tg[piece[i].y][piece[i].x]='M';
			}
		}
		for(int i=0;i<n;i++) print(tg[i]);
		print("-------------------");
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
	hash.reset();
	q.push(node(i_status,0));
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		//now.printinfo();
		if(hash[now.status%MOD]) continue;
		else hash[now.status%MOD]=1;
		int ok=now.OK();
		if(ok==1)
		{
			ans=min(ans,now.step);
			break;
		}
		elif(ok==-1) continue;
		for(int i=0;i<4;i++)
		{
			node next=now;
			if(next.move(i)) q.push(next);
		}
	}
	return ans;
}

int main()
{
	//freopen("input.txt","r",stdin);
	char cmd[4];
	while(input(n>>m))
	{
		for(int i=0;i<n;i++) scanf("%s",g[i]);

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

				if(g[i][j]!='E' && g[i][j]!='*' && g[i][j]!='R')
				{
					g[i][j]='*';
				}
			}
		}
		int status=makeStatus(pawn,mirPawn,knight,char2Dir(*cmd),0);
		int ans=bfs(status);
		if(ans>=INF) ans=-1;
		print(ans);
	}
	return 0;
}
