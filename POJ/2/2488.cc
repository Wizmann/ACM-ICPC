#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <iostream>

using namespace std;

typedef struct point
{
	int x,y;
	
	void setpoint(int a,int b)
	{
		x=a;y=b;
	}
}point;

char board[30][30];
int x,y;
int my[8]= {-2,-2, -1,-1, 1, 1, 2,2};
int mx[8]= {-1, 1, -2, 2,-2, 2,-1,1};

const int move=8;
int n;
int cas=1;

stack<point> print;

int dfs(point pos)
{
	print.push(pos);
	n++;
	if(n==x*y) return 1;
	int tx=pos.x;
	int ty=pos.y;
	//printf("%d %d\n",tx,ty);
	board[tx][ty]=1;
	for(int i=0;i<move;i++)
	{
		if(tx+mx[i]>0&&tx+mx[i]<=x && ty+my[i]>0&&ty+my[i]<=y && !board[tx+mx[i]][ty+my[i]])
		{
			pos.setpoint(tx+mx[i],ty+my[i]);			
			if(dfs(pos)) return 1;
		}
	}
	//printf("%d %d\n",print.front().x,print.front().y);
	print.pop();
	board[tx][ty]=0;
	n--;
	return 0;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	point start;
	scanf("%d",&t);
	while(t--)
	{
		n=0;
		printf("Scenario #%d:\n",cas++);
		memset(board,0,sizeof(board));
		scanf("%d%d",&x,&y);
		while(!print.empty()) print.pop();
		
		start.setpoint(1,1);		
		
		if(!dfs(start)) puts("impossible");
		else
		{
			stack<point> temp;
			while(!print.empty())
			{
				start=print.top();
				temp.push(start);
				print.pop();
			}
			while(!temp.empty())
			{
				start=temp.top();
				printf("%c%d",start.y+'A'-1,start.x);
				temp.pop();
			}				
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
