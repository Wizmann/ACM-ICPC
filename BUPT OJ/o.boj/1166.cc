#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int mx[8]={1,1,2,2,-1,-1,-2,-2},my[8]={2,-2,1,-1,2,-2,1,-1};

typedef struct point
{
	int x,y;
	int step;
	
	void setpoint(int a,int b,int c)
	{
		x=a;y=b;step=c;
	}
	
	void move(int dx,int dy)
	{
		x+=dx;y+=dy;step++;
	}
	
	void operator = (point &b)
	{
		x=b.x;
		y=b.y;
		step=b.step;
	}
	
	friend bool operator == (const point &a,const point &b)
	{
		return (a.x==b.x&&a.y==b.y);
	}
}point;

point s,e;
char chess[10][10];
int minmove=1<<20;

void bfs()
{
	queue<point> search;
	while(search.size()) search.pop();
	search.push(s);
	while(search.size())
	{
		point temp=search.front();
		search.pop();
		
		if(temp.step>=minmove) continue;
		else
		{
			for(int i=0;i<8;i++)
			{
				point move=temp;
				move.move(mx[i],my[i]);
				if(move==e)
				{
					if(move.step<minmove) minmove=move.step;
				}
				else if(move.x>=0&&move.x<8&&move.y>=0&&move.y<8) search.push(move);
			}
		}
	}
}
		

int main()
{
	freopen("input.txt","r",stdin);
	char st[5],end[5];
	while(scanf("%s%s",st,end)!=EOF)
	{
		minmove=1<<20;
		s.setpoint(*st-'a',*(st+1)-'0'-1,0);
		e.setpoint(*end-'a',*(end+1)-'0'-1,0);
		
		if(s==e) minmove=0;
		else bfs();
		
		printf("To get from %c%d to %c%d takes %d knight moves.\n",s.x+'a',s.y+1,e.x+'a',e.y+1,minmove);
	}
	return 0;
}
	
		
		
	
