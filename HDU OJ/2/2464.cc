//Result:2012-09-02 14:00:59	Accepted	2464	140MS	488K	1218 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
const int INF=1<<28;
const int SIZE=12;

int ga[SIZE][SIZE],gb[SIZE][SIZE];

int pera[SIZE],perb[SIZE];

int n,mb,ma;
int ia,ib,da,db;

int slove()
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int ta=ga[pera[i]][pera[j]];
			int tb=gb[perb[i]][perb[j]];
			
			if(ta!=tb)
			{
				if(ta>tb) res+=min(ib,da);
				else res+=min(ia,db);
			}
		}
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,cas=1;
	while(scanf("%d%d%d",&n,&ma,&mb) && (n||ma||mb))
	{
		memset(ga,0,sizeof(ga));
		memset(gb,0,sizeof(gb));
		scanf("%d%d%d%d",&ia,&ib,&da,&db);
		for(int i=0;i<n;i++)
		{
			pera[i]=perb[i]=i;
		}
		for(int i=0;i<ma;i++)
		{
			scanf("%d%d",&a,&b);
			ga[a][b]++;
			ga[b][a]++;
		}
		for(int i=0;i<mb;i++)
		{
			scanf("%d%d",&a,&b);
			gb[a][b]++;
			gb[b][a]++;
		}
		int res=INF;
		do
		{
			res=min(res,slove());
		}while(next_permutation(pera,pera+n));
		printf("Case #%d: %d\n",cas++,res);
	}
	return 0;
}


