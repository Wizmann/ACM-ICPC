//Result: wizmann	1308	Accepted	740K	0MS	G++	1152B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define pb push_back

int intree[SIZE],outtree[SIZE];
vector<int> g[SIZE];

int main()
{
    freopen("input.txt","r",stdin);
	int cas=1;
	int a,b;
	while(input(a>>b) && a>=0 && b>=0)
	{
        if(a+b==0)
        {
            printf("Case %d is a tree.\n",cas++);
            continue;
        }
		memset(intree,0,sizeof(intree));
		memset(outtree,0,sizeof(outtree));
		for(int i=0;i<SIZE;i++) g[i].clear();
		intree[b]++;outtree[a]++;
		g[a].pb(b);
		while(input(a>>b) && a && b)
		{
			intree[b]++;
			outtree[a]++;
			g[a].pb(b);
		}
        bool flag=true;
        int t=0;
        for(int i=0;i<SIZE;i++)
        {
            if(!intree[i] && outtree[i]) t++;
            if(intree[i] && intree[i]!=1) flag=false;
        }
        //print(t);
        if(t!=1) flag=false;
		if(flag)
		{
			printf("Case %d is a tree.\n",cas++);
		}
		else printf("Case %d is not a tree.\n",cas++);
	}
	return 0;
}
