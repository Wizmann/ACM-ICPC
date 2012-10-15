//Result:4772	FM	Accepted	C++	0.096	2012-10-13 06:07:27
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512
#define INF 0x3f3f3f3f

int n,m;
int g[SIZE][SIZE];
char visx[SIZE],visy[SIZE];
int linky[SIZE];
int lx[SIZE],ly[SIZE];
int slack;

bool dfs(int x)
{
	visx[x]=1;
	for(int y=0;y<m;y++)
	{
		if(visy[y]) continue;
		int t=lx[x]+ly[y]-g[x][y];
		if(!t)
		{
			visy[y]=1;
			if(linky[y]==-1 || dfs(linky[y]))
			{
				linky[y]=x;
				return 1;
			}
		}
		else if(t<slack) slack=t;
	}
	return 0;
}

int km()
{
	memset(linky,-1,sizeof(linky));
	memset(lx,0,sizeof(lx));
	memset(ly,0,sizeof(ly));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			lx[i]=max(lx[i],g[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			slack=INF;
			if(dfs(i)) break;
			for(int j=0;j<n;j++)
			{
				if(visx[j]) lx[j]-=slack;
			}
			for(int j=0;j<m;j++)
			{
				if(visy[j]) ly[j]+=slack;
			}
		}
	}
	int res=0;
	for(int i=0;i<m;i++)
	{
		if(linky[i]!=-1)
		{
			res+=lx[linky[i]]+ly[i];
		}
	}
	return res;
}

/*
//GK, DC, DL, DR, MC, ML, MR, FS
1GK, 2DCs, 1DL, 1DR, 2MCs, 1ML, 1MR, 2FSs
1GK, 2DCs, 1DL, 1DR, 3MCs, 1ML, 1MR, 1FS
1GK, 2DCs, 1DL, 1DR, 3MCs, 0ML, 0MR, 3FSs
1GK, 3DCs, 0DL, 0DR, 3MCs, 1ML, 1MR, 2FSs
1GK, 3DCs, 0DL, 0DR, 4MC,  1ML, 1MR, 1FS
1GK, 3DCs, 1DL, 1DR, 3MC,  0ML, 0MR, 2FSs
1GK, 4DCs, 1DL, 1DR, 3MC,  0ML, 0MR, 1FS
*/
const int format[7][8]={
	//GK, DC, DL, DR, MC, ML, MR, FS
	{1,2,1,1,2,1,1,2},
	{1,2,1,1,3,1,1,1},
	{1,2,1,1,3,0,0,3},
	{1,3,0,0,3,1,1,2},
	{1,3,0,0,4,1,1,1},
	{1,3,1,1,3,0,0,2},
	{1,4,1,1,3,0,0,1}};

int able[SIZE][12];

void buildG(int x)
{
	memset(g,0,sizeof(g));
	int ptr=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<format[x][i];j++)
		{
			for(int k=0;k<m;k++)
			{
				g[ptr][k]=able[k][i];
			}
			ptr++;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	char name[256];
	while(input(m) && m)
	{
		int ans=-INF,ff=-1;
		n=11;//Player
		for(int i=0;i<m;i++)
		{
			scanf("%s",name);
			for(int j=0;j<8;j++)
			{
				scanf("%d",&able[i][j]);
			}
		}
		vector<int> anslist;
		for(int i=0;i<7;i++)
		{
			buildG(i);
			int tmp=km();
			if(tmp>ans)
			{
				anslist.clear();
				ans=tmp;
			}
			if(tmp>=ans)
			{
				anslist.push_back(i);
			}
		}
		for(int i=0;i<(int)anslist.size();i++)
		{
			ff=anslist[i];
			string ffname;
			if(ff<6) ffname+='A'+ff;
			else ffname="China";
			printf("Formation %s has the highest points %d.\n",ffname.c_str(),ans);
		}
		puts("");
	}
	return 0;
}
