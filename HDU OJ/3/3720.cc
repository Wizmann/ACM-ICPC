//Result:2012-09-13 21:51:22	Accepted	3720	125MS	320K	2112 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<28

struct player
{
	int nr,abl;
	player(){}
	player(int inr,int iabl)
	{
		nr=inr;abl=iabl;
	}

	friend bool operator < (const player &a,const player &b)
	{
		return a.abl>b.abl;
	}
};

vector<player> vec[4];
int g[32][32];
map<string,int> mp;
int ind,ans;
int on[32];
int power[128];

void addToVec(char *name,int abl,char *pos)
{
	if(mp.find(name)==mp.end())
	{
		mp[name]=ind++;
	}

	if(*pos=='g') vec[0].push_back(player(mp[name],abl));
	else if(*pos=='d') vec[1].push_back(player(mp[name],abl));
	else if(*pos=='m') vec[2].push_back(player(mp[name],abl));
	else if(*pos=='s') vec[3].push_back(player(mp[name],abl));
	else puts("ERROR");
	
	
	power[mp[name]]=abl;
}

void dfs(int pos,int now,int ptr)
{
	if(pos==0 && ptr==1) dfs(1,0,ptr);
	else if(pos==1 && ptr==5) dfs(2,0,ptr);
	else if(pos==2 && ptr==9) dfs(3,0,ptr);
	else if(pos==3 && ptr==11)
	{
		int sum=0;
		for(int i=0;i<11;i++)
		{
			sum+=power[on[i]];
			for(int j=0;j<i;j++)
			{
				sum+=g[on[i]][on[j]];
			}
		}
		ans=max(ans,sum);
	}
	else
	{
		for(int i=now;i<(int)vec[pos].size();i++)
		{
			on[ptr++]=vec[pos][i].nr;
			dfs(pos,i+1,ptr);
			on[ptr]=0;
			ptr--;
		}
	}
}


void slove()
{
	dfs(0,0,0);
}

int main()
{
	freopen("input.txt","r",stdin);
	char name[64],pos[64];
	int abl,k;
	while(scanf("%s%d%s",name,&abl,pos)!=EOF)
	{
		for(int i=0;i<4;i++) vec[i].clear();
		ind=0;ans=-INF;
		mp.clear();
		memset(power,0,sizeof(power));
		addToVec(name,abl,pos);
		for(int i=1;i<23;i++)
		{
			scanf("%s%d%s",name,&abl,pos);
			addToVec(name,abl,pos);
		}
		memset(g,0,sizeof(g));
		input(k);
		for(int i=0;i<k;i++)
		{
			scanf("%s%s%d",name,pos,&abl);
			int a=mp[name];
			int b=mp[pos];
			g[a][b]=g[b][a]=abl;
		}
		slove();
		if(ans==-INF) puts("impossible");
		else print(ans);
	}
	return 0;
}


	
