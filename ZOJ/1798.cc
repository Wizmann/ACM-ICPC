//Result:2012-03-05 21:48:56	 Accepted	1798	C++	0	188	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 12

vector<int> g[SIZE];
int n;
char visit[SIZE];

bool dfs(int now,int step=0)
{
	if(now==0 && step==n+1) return true;

	for(int i=0;i<(int)g[now].size();i++)
	{
		int p=g[now][i];
		if(!visit[p])
		{
			visit[p]=1;
			if(dfs(p,step+1)) return true;
			visit[p]=0;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int cas=1;
	while(input(n) && n)
	{
		for(int i=0;i<SIZE;i++) g[i].clear();
		memset(visit,0,sizeof(visit));
		int a;
		char cmd[SIZE];
		for(int i=1;i<=n;i++)
		{
			do
			{
				gets(cmd);
			}while(*cmd=='\0');
			char *p=cmd;
			while(sscanf(p,"%d",&a)!=EOF)
			{
				//print(i<<' '<<a);
				g[i].push_back(a);
				g[a].push_back(i);
				while(*p!=' '&&*p!='\0') p++;
				while(*p==' '&&*p!='\0') p++;
			}
		}
		bool flag=dfs(0);
		printf("Case %d: ",cas++);
		if(flag) printf("Granny can make the circuit.\n");
		else printf("Granny can not make the circuit.\n");
	}
	return 0;
}

		
