#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010

struct CProc{int con[3],req[3];};

CProc proc[SIZE];
int res[3],que[3][SIZE];
char visit[SIZE];
int n,m,sort_key;

inline bool cmp(int a,int b)
{
	return proc[a].req[sort_key]<proc[b].req[sort_key];
}

bool slove()
{
	int ptr[3]={0};
	int ok=0;
	while(1)
	{
		bool lock=true;
		for(int i=0;i<m;i++)
		{
			for(int j=ptr[i];j<n;j++)
			{
				int nr=que[i][j];
				if(proc[nr].req[i]>res[i]) break;
				else
				{
					ptr[i]++;
					visit[nr]|=(1<<i);
					lock=false;
					if(visit[nr]==((1<<m)-1))
					{
						for(int k=0;k<m;k++) res[k]+=proc[nr].con[k];
						ok++;
					}
				}
			}
		}
		if(lock) break;
	}
	if(ok==n) return true;
	else return false;
}

int main()
{
	while(input(n>>m))
	{
		memset(visit,0,sizeof(visit));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++) scanf("%d",&(proc[j].con[i]));
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++) scanf("%d",&(proc[j].req[i]));
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++) que[j][i]=i;
		}
		for(int i=0;i<m;i++)
		{
			sort_key=i;
			sort(que[i],que[i]+n,cmp);
		}
		for(int i=0;i<m;i++) scanf("%d",&res[i]);
		if(slove()) puts("Yes");
		else puts("No");
	}
	return 0;
}

