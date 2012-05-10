//Result:wizmann	3768	Accepted	18436K	172MS	G++	1379B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 3010
#define FATHER 16

char father[FATHER][FATHER];
char son[2][SIZE][SIZE];

int n;
int gen;

void fill_graph(int ptr,int y,int x)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			son[ptr][i+y][j+x]=father[i][j];
		}
	}
}

void draw(int ptr,int t)
{
	int sz=1;
	for(int i=0;i<t;i++) sz*=n;
	int pre=ptr^1;
	memset(son[ptr],0,sizeof(son[ptr]));
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<sz;j++)
		{
			if(son[pre][i][j]!=' ' && son[pre][i][j])
			{
				fill_graph(ptr,n*i,n*j);
				//print(n*i<<' '<<n*j);
			}
		}
	}
}
	

void slove()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) son[0][i][j]=father[i][j];
	}
	int ptr=1;
	for(int i=1;i<gen;i++)
	{
		draw(ptr,i);
		ptr^=1;
	}
	int pre=ptr^1;
	int sz=1;
	for(int i=0;i<gen;i++) sz*=n;
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<sz;j++)
		{
			son[pre][i][j]=son[pre][i][j]?son[pre][i][j]:' ';
		}
		puts(son[pre][i]);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;i++)
		{
			do
			{
				gets(father[i]);
			}while(*father[i]==0 || *father[i]=='\n');
		}
		scanf("%d",&gen);
		slove();
	}
	return 0;
}
	
