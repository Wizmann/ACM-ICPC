//Result:wizmann	2632	Accepted	240K	0MS	C++	1849B	2011-09-23 16:47:56

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl

const int mx[]={0,1,0,-1};
const int my[]={1,0,-1,0};

int g[120][120];

typedef struct pnt
{
	int x,y,dir;

	void setpnt(int a,int b,char c)
	{
		x=a;y=b;
		switch(c)
		{
			case 'N':dir=0;break;
			case 'E':dir=1;break;
			case 'S':dir=2;break;
			case 'W':dir=3;break;
			default:print(c);break;
		}
	}

	void changeDir(char c)
	{
		switch(c)
		{
			case 'L':dir=(dir+3)%4;break;
			case 'R':dir=(dir+1)%4;break;
		}
	}
	
	void forward()
	{
		g[x][y]=0;
		x+=mx[dir];
		y+=my[dir];
	}
}pnt;

int t;
int l,w,robot,cmd;

pnt array[120];

int isCrash(int t)
{
	int x=array[t].x,y=array[t].y;
	//print(x);print(y);
	if( (x<=0||x>w)||(y<=0||y>l) ) return -1;
	else
	{
		if(g[x][y]) return g[x][y];
		else
		{
			g[x][y]=t;
			return 0;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	char temp[5];
	scanf("%d",&t);
	while(t--)
	{
		bool flag=true;
		memset(g,0,sizeof(g));
		memset(array,0,sizeof(array));
		scanf("%d%d",&w,&l);
		scanf("%d%d",&robot,&cmd);
		int ta,tb;
		for(int i=1;i<=robot;i++)
		{
			scanf("%d%d%s",&ta,&tb,temp);
			array[i].setpnt(ta,tb,*temp);
			g[ta][tb]=i;
		}
		while(cmd--)
		{
			scanf("%d%s%d",&ta,temp,&tb);
			if(!flag) continue;
			if(*temp=='F')
			{
				while(tb--)
				{
					array[ta].forward();
					int ans=isCrash(ta);
					if(!ans) continue;
					else
					{
						if(ans==-1) printf("Robot %d crashes into the wall\n",ta);
						else printf("Robot %d crashes into robot %d\n",ta,ans);
						flag=false;
					}
					if(!flag) break;
				}
			}
			else
			{
				while(tb--) array[ta].changeDir(*temp);
			}
		}
		if(flag) print("OK");
	}
	return 0;
}
				
	


