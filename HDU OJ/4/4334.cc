//Result:2012-08-02 21:15:26	Accepted	4334	2250MS	2180K	2094 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 201
#define INF 1LL<<60
#define PRIME 234569

typedef long long llint;

struct node
{
	llint val;
	int next;
	node(){}
	node(llint ival,int inext)
	{
		val=ival;
		next=inext;
	}
};

llint array[5][SIZE];
int n;
llint sum[40000];

int head[PRIME];
node g[SIZE*SIZE];
int gp;

void add_g(llint x)
{
	llint hh=(x%PRIME+PRIME)%PRIME;
	for(int i=head[hh];i!=-1;i=g[i].next)
	{
		if(g[i].val==x) return;
	}
	g[gp]=node(x,head[hh]);
	head[hh]=gp++;
}

bool g_find(llint x)
{
	llint hh=(x%PRIME+PRIME)%PRIME;
	int step=0;
	for(int i=head[hh];i!=-1;i=g[i].next)
	{
		step++;
		if(g[i].val==x) return true;
	}
	//if(step>0) print("STEP "<<step);
	return false;
}

int main()
{
	freopen("1004.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		gp=0;
		memset(head,-1,sizeof(head));
		input(n);
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%lld",&array[i][j]);
			}
		}

		int ind=0;
		bool ans=false;
		llint maxi=-INF,mini=INF;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				sum[ind]=array[0][i]+array[1][j];
				maxi=max(maxi,sum[ind]);
				mini=min(mini,sum[ind]);
				add_g(sum[ind]);
				ind++;
			}
		}
		sort(sum,sum+ind);
		sort(array[4],array[4]+n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				llint ab=array[2][i]+array[3][j];
				int st=lower_bound(array[4],array[4]+n,-(ab+maxi))-array[4];
				int end=upper_bound(array[4],array[4]+n,-(ab+mini))-array[4];
				for(int k=st;k<end;k++)
				{
					llint t=array[2][i]+array[3][j]+array[4][k];
					if(t+mini>0 || t+maxi<0) continue;
					else
					{
						llint f=-t;
						if(g_find(f))
						{
							ans=true;
							goto end_of_the_end;
						}
					}
				}
			}
		}

end_of_the_end:
		puts(ans?"Yes":"No");
	}
	//printf("%.3lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}


/*--------------------------------------------------------------------*/



//Result:2012-08-02 21:35:34	Accepted	4334	1000MS	884K	1055 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 200

typedef long long llint;

llint array[5][SIZE];
int n;
llint a[SIZE*SIZE],b[SIZE*SIZE];
int pa,pb;

bool query(llint val)
{
	int x=0,y=pb-1;
	while(x<pa && y>=0)
	{
		llint sum=a[x]+b[y];
		if(sum==val) return true;
		else if(sum>val) y--;
		else x++;
	}
	return false;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%I64d",&array[i][j]);
			}
		}
		
		
		pa=pb=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				a[pa++]=array[0][i]+array[1][j];
				b[pb++]=array[2][i]+array[3][j];
			}
		}
		sort(a,a+pa);
		sort(b,b+pb);

		bool win=false;
		for(int i=0;i<n;i++)
		{
			if(query(-array[4][i]))
			{
				win=true;
				break;
			}
		}

		puts(win?"Yes":"No");
	}
	return 0;
}
			







