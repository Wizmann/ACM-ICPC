//Result:2012-10-05 18:37:02	Accepted	4121	0MS	280K	2693 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define N 12
#define M 12

struct node
{
	int x,y;
	char type;

	node(){}
	node(int ix,int iy,char itype)
	{
		x=ix;y=iy;type=itype;
	}
	
	bool onSamePoint(const node& a) const
	{
		if(a.x==x && a.y==y) return true;
		else return false;
	}
};

const int mx[]={0,0,1,-1};
const int my[]={1,-1,0,0};

char mp[N][M];
int n;
node win;
node array[N];

bool inHome(const node &dest)
{
	if(dest.x<4 || dest.x>6 || dest.y<1 || dest.y>3) return false;
	else return true;
}


int OnX(const node &a,const node &b)
{
	int res=0;
	int st=min(a.y,b.y);
	int end=max(a.y,b.y);
	int x=a.x;
	for(int i=st+1;i<end;i++)
	{
		if(mp[i][x]) res++;
	}
	return res;
}

int OnY(const node &a,const node &b)
{
	int res=0;
	int st=min(a.x,b.x);
	int end=max(a.x,b.x);
	int y=a.y;
	for(int i=st+1;i<end;i++)
	{
		if(mp[y][i]) res++;
	}
	return res;
}
		

bool check(const node &dest)
{
	for(int i=0;i<n;i++) if(!dest.onSamePoint(array[i]))
	{
		if(array[i].type=='G')
		{
			if(array[i].x==dest.x)
			{
				if(OnX(array[i],dest)==0) return false;//Black death
			}
		}
		else if(array[i].type=='R')
		{
			if(array[i].x==dest.x)
			{
				if(OnX(array[i],dest)==0) return false;
			}
			
			if(array[i].y==dest.y)
			{
				if(OnY(array[i],dest)==0) return false;
			}
		}
		else if(array[i].type=='C')
		{
			if(array[i].x==dest.x)
			{
				if(OnX(array[i],dest)==1) return false;
			}
			
			if(array[i].y==dest.y)
			{
				if(OnY(array[i],dest)==1) return false;
			}
		}
		else if(array[i].type=='H')
		{
			if(abs(dest.y-array[i].y)==2 && abs(dest.x-array[i].x)==1)
			{
				int nx=array[i].x;
				int ny=array[i].y+(dest.y-array[i].y)/2;
				if(!mp[ny][nx]) return false;
			}
			else if(abs(dest.x-array[i].x)==2 && abs(dest.y-array[i].y)==1)
			{
				int nx=array[i].x+(dest.x-array[i].x)/2;
				int ny=array[i].y;
				if(!mp[ny][nx]) return false;
			}
		}
	}
	return true;
}
				


bool slove()
{
	for(int i=0;i<4;i++)
	{
		node next=node(win.x+mx[i],win.y+my[i],win.type);
		if(!inHome(next)) continue;//将不在家里的时候不考虑
		if(check(next)) return true;
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	char cmd[5];
	while(input(n>>a>>b) && n+a+b)
	{
		memset(mp,0,sizeof(mp));
		win=node(b,a,'B');
		for(int i=0;i<n;i++)
		{
			scanf("%s%d%d",cmd,&a,&b);
			mp[a][b]=*cmd;
			array[i]=node(b,a,*cmd);
		}
		if(!slove()) puts("YES");
		else puts("NO");
	}
	return 0;
}



	
