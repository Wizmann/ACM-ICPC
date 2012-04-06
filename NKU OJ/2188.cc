#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

int n;
char g[SIZE][SIZE];
char paper[SIZE][SIZE];
int x,y;
string ans;

bool makeLR()
{
	if(x%2) return false;//不能折叠
	else
	{
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x/2;j++)
			{
				paper[i][j]=paper[i][x-j-1];
			}
		}
		x/=2;
		return true;
	}
}

bool makeUD()
{
	if(y%2) return false;//不能折叠
	else
	{
		for(int i=0;i<y/2;i++)
		{
			for(int j=0;j<x;j++)
			{
				paper[i][j]=paper[y-i-1][j];
			}
		}
		y/=2;
		return true;
	}
}

void getAns(int ny,int nx)
{
	//print("("<<ny<<","<<nx<<")");
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			if(paper[i][j]=='1')
			{
				ans+=g[ny+i][nx+j];
				//printf("%d,%d =>%c",ny+i,nx+j,g[ny+i][nx+j]);
			}
		}
	}
	//puts("");
}

void printPaper()
{
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			printf("%c",paper[i][j]);
		}
		puts("");
	}
	//puts("------------");
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n))
	{
		ans.clear();
		for(int i=0;i<n;i++) scanf("%s",g[i]);
		for(int i=0;i<n;i++) scanf("%s",paper[i]);
		x=y=n;
		getAns(0,0);
		while(1)
		{
			if(!makeLR()) break;
			else
			{
				//printPaper();
				for(int i=0;i<n;i+=y)
				{
					for(int j=0;j<n;j+=x)
					{
						getAns(i,j);
					}
				}
			}
			if(!makeUD()) break;
			else
			{
				//printPaper();
				for(int i=0;i<n;i+=y)
				{
					for(int j=0;j<n;j+=x) getAns(i,j);
				}
			}
		}
		print(ans);
	}
	return 0;
}
		
	
