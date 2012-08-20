//Result:wizmann	1069	Accepted	724K	891MS	G++	3006B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define llint long long
#define uint unsigned int
#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<25
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define np next_permutation

#define SIZE 25

vector<int> tri;
char hash[SIZE*2][SIZE*4];
int bsize;

bool init()
{
	for(int i=0;i<(int)tri.size();i++)
	{
		if(bsize % tri[i] == 0) return true;
	}
	
	for(int row=0;row<bsize;row++)
	{
		for(int col=0;col<=2*(bsize-row-1);col++) hash[row][col]=1;
	}
	
	for(int row=bsize;row<2*bsize;row++)
	{
		for(int col=4*bsize-2*(row-bsize)-1;col<=4*bsize-1;col++) hash[row][col]=1;
	}
	return false;
}


bool avail(int row,int col,int size)
{
	if(col%2)
	{
		for(int i=row;i<row+size;i++)
		{
			for(int j=col-2*(i-row);j<=col;j++)
			{
				if (i>=2*bsize||j>=4*bsize||hash[i][j]) return false;
			}
		}
	}
	else
	{
		for(int i=row;i<row+size;i++)
		{
			for(int j=col;j<=col+2*(row+size-i-1);j++)
			{
				if(i>=2*bsize||j>=4*bsize||hash[i][j]) return false;
			}
		}
	}
	return true;
}


int availMax(int row,int col)
{
	for(int i=tri.size()-1;i>=0;i--)
	{
		if(avail(row,col,tri[i])) return i;
	}
	return -1;
}


void change(int row,int col,int size,bool flag)
{
	if(col%2)
	{
		for(int i=row;i<row+size;i++)
		{
			for(int j=col-2*(i-row);j<=col;j++) hash[i][j]=flag;
		}
	}
	else
	{
		for(int i=row;i<row+size;i++)
		{
			for(int j=col;j<=col+2*(row+size-i-1);j++) hash[i][j]=flag;
		}
	}
}


bool dfs(int row,int col)
{
	if(row>=2*bsize) return true;
	elif(col>=4*bsize) return dfs(row+1,0);
	elif(hash[row][col])
	{
		for(int i=col;i<=4*bsize;i++)
		{
			if(!hash[row][i]) return dfs(row,i);
		}
	}
	else
	{
		int smax = availMax(row,col);
		for(int i=smax;i>=0;i--)
		{
			change(row,col,tri[i],1);
			if(dfs(row,col+1)) return true;
			change(row,col,tri[i],0);
		}
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int cas,tsize,t;
	input(cas);
	while(cas--)
	{
		memset(hash,0,sizeof(hash));
		tri.clear();
		input(bsize>>tsize);
		while(tsize--)
		{
			input(t);
			tri.pb(t);
		}
		sort(tri.begin(),tri.end());
		
		vector<int>::iterator iter,next;
		for(iter=tri.begin();iter!=tri.end();iter++)
		{
			for(next=tri.begin();next!=iter;next++)
			{
				if(*iter % *next == 0)
				{
					tri.erase(iter);
					iter--;
					break;
				}
			}
		}
		if(init()) print("YES");
		else
		{
			if(dfs(0,0)) print("YES");
			else print("NO");
		}
	}
	//print((double)clock()/CLOCKS_PER_SEC);
	return 0;
}
