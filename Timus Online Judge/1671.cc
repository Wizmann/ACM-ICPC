/* Result:
 * 15:47:51 13 Jul 2012	
 * Wizmann
 * 1671. Anansi's Cobweb
 * C++
 * Accepted	
 * 0.156
 * 2 176 KB
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<30
#define inf 1e30
#define eps 1e-9
#define pb push_back
#define SIZE 100005

struct edge
{
	int s,t;
	edge(){}
	edge(int i_s,int i_t)
	{
		s=i_s;t=i_t;
	}
};

int n,m,q;


int father[SIZE];
edge g[SIZE];
bitset<SIZE> ok;
int add[SIZE];
int ans;
int res[SIZE];

int findfather(int x)
{
	if(father[x]==x) return x;
	else return father[x]=findfather(father[x]);
}

void addedge(int nr)
{
	int s=g[nr].s;
	int t=g[nr].t;
	
	int sfa=findfather(s);
	int tfa=findfather(t);
	
	if(sfa!=tfa)
	{
		ans--;
		father[tfa]=sfa;
	}
}
	
	

int main()
{
	freopen("e.txt","r",stdin);
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<SIZE;i++) father[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		g[i]=edge(a,b);
	}
	ans=n;
	input(q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&a);
		add[i]=a;
		ok[a]=1;
	}
	for(int i=1;i<=m;i++)
	{
		if(!ok[i]) addedge(i);
	}
	res[0]=ans;
	int ind=1;
	for(int j=q;j>0;j--)
	{
		addedge(add[j]);
		res[ind++]=ans;
	}
	for(int i=ind-2;i>=0;i--)
	{
		if(i!=ind-2) printf(" ");
		printf("%d",res[i]);
	}
	return 0;
}
	
	
	
