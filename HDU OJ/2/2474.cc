//Result:2012-08-20 14:23:04	Accepted	2474	203MS	2284K	1925 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010

struct node
{
	int con[3];
	int req[3];
	bool ok;
};

node job[SIZE];
int key[3];
int que[3][SIZE];
int n,m;
bitset<SIZE> visit[3];

bool cmp0(int a,int b)
{
	return job[a].req[0]<job[b].req[0];
}
bool cmp1(int a,int b)
{
	return job[a].req[1]<job[b].req[1];
}
bool cmp2(int a,int b)
{
	return job[a].req[2]<job[b].req[2];
}

inline bool can_make(int nr)
{
	for(int i=0;i<m;i++)
	{
		if(job[nr].req[i]>key[i]) return false;
	}
	return true;
}

bool slove()
{
	int ptr[3]={0};
	int ok=0;
	while(1)
	{
		bool flag=false;
		for(int i=0;i<m;i++)
		{
			for(int j=ptr[i];j<n;j++)
			{
				int nr=que[i][j];
				if(job[nr].req[i]>key[i]) break;
				else
				{
					ptr[i]++;
					visit[i][nr]=1;
					bool fin=true;
					flag=true;
					for(int k=0;k<m;k++)
					{
						if(!visit[k][nr]) fin=false;
					}
					if(fin)
					{
						for(int k=0;k<m;k++)
						{
							key[k]+=job[nr].con[k];
						}
						ok++;
					}
				}
			}
		}
		if(!flag) break;
	}
	if(ok==n) return true;
	else return false;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	bool (*cmp[3])(int,int)={cmp0,cmp1,cmp2};
	while(input(n>>m))
	{
		for(int i=0;i<3;i++)
		{
			visit[i].reset();
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&(job[j].con[i]));
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&(job[j].req[i]));
			}
		}
		for(int i=0;i<n;i++)
		{
			que[0][i]=que[1][i]=que[2][i]=i;
			job[i].ok=false;
		}
		for(int i=0;i<m;i++)
		{
			sort(que[i],que[i]+n,cmp[i]);
		}
		for(int i=0;i<m;i++) scanf("%d",&key[i]);
		if(slove()) puts("Yes");
		else puts("No");
	}
	return 0;
}
