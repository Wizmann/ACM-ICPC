//Result:wizmann	3434	Accepted	1836K	2219MS	G++	4337B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define SIZE 1024
#define elif else if

typedef struct cpoint
{
	int x,y;
	
	cpoint(){}
	
	cpoint(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}
	
	inline void setpoint(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}		
}cpoint;

typedef struct snake
{
	char name;
	int pos;
	cpoint head;
	queue<cpoint> body;
}snake;

int n,k;
char g[SIZE][SIZE],visit[SIZE][SIZE];
int nsnake=0;
snake array[26];

const int mx[]={0, 1,0,-1};
const int my[]={-1,0,1, 0};

inline void setvisit(const cpoint& cp)
{
	visit[cp.y][cp.x]=1;
}

inline bool visited(const cpoint& cp)
{
	return visit[cp.y][cp.x];
}

inline void printMap()
{
	for(int i=0;i<n;i++)
	{
		printf("%s\n",g[i]);
	}
	//print("------------------");
}

int cmp(const void *a,const void *b)
{
	snake *ta=(snake*)a,*tb=(snake*)b;
	
	return ta->name-tb->name;
}

void fill_body(int x)
{
	stack<cpoint> tmp;
	bool first=true;
	queue<cpoint> bfs;
	cpoint head=array[x].head;
	bfs.push(head);
	memset(visit,0,sizeof(visit));
	visited(head);
	while(!bfs.empty())
	{
		cpoint t=bfs.front();
		bfs.pop();
		for(int i=0;i<4;i++)
		{
			cpoint tt;
			tt.x=t.x+mx[i];
			tt.y=t.y+my[i];
			if(!visited(tt) && g[tt.y][tt.x]==array[x].name)
			{
				bfs.push(tt);
				tmp.push(tt);
				if(first)
				{
					int tx=head.x-tt.x;
					int ty=head.y-tt.y;
					for(int j=0;j<4;j++)
					{
						if(tx==mx[j] && ty==my[j]) array[x].pos=j;
					}
					first=false;
					if(array[x].pos<0 || array[x].pos>3) print("ERROR");
				}
			}
			setvisit(tt);
		}
	}
	while(!tmp.empty())
	{
		array[x].body.push(tmp.top());
		tmp.pop();
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	input(n>>k);
	for(int i=0;i<n;i++)
	{
		scanf("%s",g[i]);
		for(int j=0;g[i][j];j++)
		{
			if(g[i][j]>='A' && g[i][j]<='Z')
			{
				array[nsnake].head.setpoint(j,i);
				array[nsnake].name=g[i][j]-'A'+'a';
				nsnake++;
			}
		}
	}
	
	qsort(array,nsnake,sizeof(snake),cmp);
	
	for(int i=0;i<nsnake;i++) fill_body(i);
	
	//TODO:
	//TO SIMULATE THE MOVE OF THE SNAKE
	//
	//WIZMANN, the bad_allocer
	//17:05 11-12-6
	
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<nsnake;j++)
		{
			int pos=array[j].pos;
			if(array[j].head.y+my[pos]>=0 && array[j].head.y+my[pos]<n &&
				array[j].head.x+mx[pos]>=0 && array[j].head.x+mx[pos]<n &&
				g[array[j].head.y+my[pos]][array[j].head.x+mx[pos]]=='.')
			{
				array[j].body.push(cpoint(array[j].head.x,array[j].head.y));
				g[array[j].head.y][array[j].head.x]=array[j].name;
				array[j].head.y+=my[pos];
				array[j].head.x+=mx[pos];
				g[array[j].head.y][array[j].head.x]=array[j].name-'a'+'A';
				
				cpoint now=array[j].body.front();
				g[now.y][now.x]='.';
				array[j].body.pop();
			}
			else
			{
				int left=(pos-1)<0?(pos+3):(pos-1);
				int right=(pos+1)%4;
				
				if(array[j].head.y+my[right]>=0 && array[j].head.y+my[right]<n &&
					array[j].head.x+mx[right]>=0 && array[j].head.x+mx[right]<n &&
					g[array[j].head.y+my[right]][array[j].head.x+mx[right]]=='.')
				{
					array[j].body.push(cpoint(array[j].head.x,array[j].head.y));
					g[array[j].head.y][array[j].head.x]=array[j].name;
					array[j].head.y+=my[right];
					array[j].head.x+=mx[right];
					g[array[j].head.y][array[j].head.x]=array[j].name-'a'+'A';
					cpoint now=array[j].body.front();
					g[now.y][now.x]='.';
					array[j].body.pop();
					array[j].pos=right;
				}
				else if(array[j].head.y+my[left]>=0 && array[j].head.y+my[left]<n &&
					array[j].head.x+mx[left]>=0 && array[j].head.y+mx[left]<n &&
					g[array[j].head.y+my[left]][array[j].head.x+mx[left]]=='.')
				{
					array[j].body.push(cpoint(array[j].head.x,array[j].head.y));
					g[array[j].head.y][array[j].head.x]=array[j].name;
					array[j].head.y+=my[left];
					array[j].head.x+=mx[left];
					g[array[j].head.y][array[j].head.x]=array[j].name-'a'+'A';
					cpoint now=array[j].body.front();
					g[now.y][now.x]='.';
					array[j].body.pop();
					array[j].pos=left;
				}
				
			}
			//printMap();
		}
	}
	printMap();

	return 0;
}
