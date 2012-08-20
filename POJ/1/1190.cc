//Result:wizmann	1190	Accepted	720K	0MS	G++	1076B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<30

int minV[21],minS[21];

void init(){
    minV[0]=0;
    minS[0]=1;
    for (int i=1;i<21;i++)
    {
        minV[i]=minV[i-1]+i*i*i;
        minS[i]=minS[i-1]+2*i*i;
    }
}

int ans,level;
inline int mul(int x)
{
	return x*x;
}

void dfs(int l,int r,int h,int dv,int s)
{
	if(l==0)
	{
		if(dv==0) ans=min(ans,s);
		return;
	}

	if(r>1 and 2*dv/(r-1)+s>=ans) return;
	if(dv-minV[l]<0 or s+minS[l]>=ans) return;
	for(int i=r-1;i>=l;i--)
	{
		if(l==level) s=mul(i);
		int hmax=(double)dv/mul(i);
		if(hmax>h-1) hmax=h-1;
		for(int j=hmax;j>=l;j--)
		{
			dfs(l-1,i,j,dv-mul(i)*j,s+2*i*j);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int v;
	init();
	input(v>>level);
	ans=INF;
	int maxR=sqrt((double)v/level)+1;
	int maxH=(double)v/mul(level)+1;
	dfs(level,maxR,maxH,v,0);
	ans=ans>=INF?-1:ans;
	print(ans);
	return 0;
}
