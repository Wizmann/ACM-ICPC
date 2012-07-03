//Result:4856	OmniGravity	Accepted	C++	1.328	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 8
#define elif else if
const int mx[]={0,1,0,-1};
const int my[]={1,0,-1,0};

const int ex[]={0,1,0,1};
const int ey[]={0,0,1,1};

bitset<20000000> visit;
char g[SIZE+2][SIZE+2];

struct point
{
	int x,y;
	point()
	{
		x=y=-1;
	}
	point(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}
};

struct node
{
	int status;

	void roll(int dir)
	{
		int st=status;
		point block[4];
		for(int i=0;i<4;i++)
		{
			int a=7&st;
			st>>=3;
			int b=7&st;
			st>>=3;
			block[3-i]=point(b,a);
			//print(b<<' '<<a);
		}
		//print("--------");
		
		//for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				for(int k=0;k<4;k++)
				{
					//print(dir<<' '<<i<<' '<<j<<' '<<k);
					bool flag=true;
					point mp=point(block[k].x+mx[dir],block[k].y+my[dir]);
					point now[4];
					point peer[12];
					for(int l=0;l<4;l++)
					{
						now[l]=point(mp.x+ex[l],mp.y+ey[l]);
					}
					int ind=0;
					for(int l=0;l<4;l++) if(l!=k)
					{
						for(int m=0;m<4;m++)
						{
							peer[ind++]=point(block[l].x+ex[m],block[l].y+ey[m]);
						}
					}
						
					for(int l=0;l<4;l++)
					{
						if(now[l].x>=0 && now[l].x<SIZE && now[l].y>=0 && now[l].y<SIZE)
						{
							if(g[now[l].y][now[l].x]=='#')
							{
								flag=false;
								break;
							}
							for(int m=0;m<ind;m++) if(flag)
							{
								if(now[l].x==peer[m].x && now[l].y==peer[m].y)
								{
									flag=false;
									break;
								}
							}
						}
						else
						{
							flag=false;
							break;
						}
					}
					if(flag) block[k]=mp;
				}
			}
		}
		st=0;
		for(int i=0;i<4;i++)
		{
			st<<=3;
			st|=block[i].x;
			st<<=3;
			st|=block[i].y;
		}
		status=st;
	}
};

int bfs(const node& init)
{
	int ans=0;
	queue<node> q;
	q.push(init);
	visit.reset();
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			node next=now;
			next.roll(i);
			
			if(!visit[next.status])
			{
				ans++;
				visit[next.status]=1;
				q.push(next);
			}
		}
	}
	/*
	set<int>::iterator iter=RollSet.begin();
	while(iter!=RollSet.end())
	{
		int st=*iter;
		for(int i=0;i<4;i++)
		{
			int a=7&st;
			st>>=3;
			int b=7&st;
			st>>=3;
			print(b<<' '<<a);
		}
		print("------------------");
		iter++;
	}
	*/
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	int cas=1;
	while(T--)
	{
		printf("Case %d: ",cas++);
		for(int i=0;i<SIZE;i++) scanf("%s",g[i]);
		point pnt[4];
		
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				if(g[i][j]>='A' && g[i][j]<='D')
				{
					int nr=g[i][j]-'A';
					if(pnt[nr].x==-1)
					{
						pnt[nr]=point(j,i);
					}
				}

				if(g[i][j]!='#') g[i][j]='.';
			}
		}

		node init;
		int st=0;
		for(int i=0;i<4;i++)
		{
			st<<=3;
			st|=pnt[i].x;
			st<<=3;
			st|=pnt[i].y;
		}
		init.status=st;
		print(bfs(init));
	}
	return 0;
}






