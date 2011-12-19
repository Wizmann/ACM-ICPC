//Result:1772 	Accepted	471MS	288K	G++	1221B	2011-11-16 12:26:55
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 16
#define ROAD 64
#define INF 1<<25

using namespace std;

map<string,int> typeName;
bitset<SIZE> visit;
bitset<ROAD> able[SIZE];

int typeNum;
int n,m;


int main()
{
	freopen("input.txt","r",stdin);
	string name;
	while(input(n) && n)
	{
		typeNum=0;
		typeName.clear();
		for(int i=0;i<n;i++) able[i].reset();
		for(int i=0;i<n;i++)
		{
			input(name);
			input(m);
			for(int j=1;j<=m;j++)
			{
				input(name);
				if(typeName.find(name)==typeName.end())
				{
					typeName[name]=typeNum++;
				}
				able[i][typeName[name]]=1;
			}
		}
		
		int ans=INF;
		for(int i=0;i<(1<<n);i++)
		{
			visit.reset();
			bitset<SIZE> bs(i);
			bitset<ROAD> res;
			for(int j=0;j<n;j++)
			{
				if(bs[j])
				{
					for(int k=0;k<ROAD;k++)
					{
						if(able[j][k]) res[k]=1;
					}
				}
			}
			//print("RES:"<<res.count());
			if((int)res.count()==(int)typeName.size())
			{
				ans=min(ans,(int)bs.count());
			}
		}
		print(ans);
	}
	return 0;
}
						
						
