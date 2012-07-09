//Result:2012-07-09 19:31:45	Accepted	3220	62MS	784K	2418 B	G++	Wizmann
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

typedef long long llint;

struct line
{
	int a,b;
	line(){}
	line(int i_a,int i_b)
	{
		a=i_a;b=i_b;
	}
};

line array[100];
int ind=0;

void init()
{
	array[0] = line(0,1);
	array[1] = line(1,3);
	array[2] = line(3,11);
	array[3] = line(11,10);
	array[4] = line(10,8);
	array[5] = line(8,0);
	array[6] = line(10,2);
	array[7] = line(2,3);
	array[8] = line(8,9);
	array[9] = line(9,1);
	array[10] = line(9,11);
	array[11] = line(0,2);
	array[12] = line(0,4);
	array[13] = line(1,5);
	array[14] = line(3,7);
	array[15] = line(11,15);
	array[16] = line(10,14);
	array[17] = line(8,12);
	array[18] = line(9,13);
	array[19] = line(2,6);
	array[20] = line(12,13);
	array[21] = line(13,5);
	array[22] = line(13,15);
	array[23] = line(4,6);
	array[24] = line(14,6);
	array[25] = line(6,7);
	array[26] = line(12,4);
	array[27] = line(4,5);
	array[28] = line(5,7);
	array[29] = line(7,15);
	array[30] = line(15,14);
	array[31] = line(14,12);
}

int light;
const int end=65280;

int hash[1<<16];


struct node
{
	int step,res;
	node(){}
	node(int i_step,int i_res)
	{
		step=i_step;
		res=i_res;
	}
};

int bfs()
{
	queue<node> q;
	q.push(node(0,end));
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		
		if(now.step>3) continue;
		
		if(hash[now.res]==-1) hash[now.res]=now.step;
		else if(hash[now.res]!=-1) continue;
		
		for(int i=0;i<32;i++)
		{
			int l=now.res;
			int a=array[i].a;
			int b=array[i].b;
			int ta=l&(1<<a)?1:0;
			int tb=l&(1<<b)?1:0;
			if(ta!=tb)
			{
				l^=(1<<a);
				l^=(1<<b);
				
				q.push(node(now.step+1,l));
			}
		}
	}
	return INF;
}

int main()
{
	freopen("a.txt","r",stdin);
	//freopen("a.out","w",stdout);
	memset(hash,-1,sizeof(hash));
	int T,a;
	init();
	input(T);
	int cas=1;
	bfs();
	while(T--)
	{
		printf("Case #%d: ",cas++);
		light=0;
		for(int i=0;i<16;i++)
		{
			scanf("%d",&a);
			light|=(a<<i);
		}
		int ans=hash[light];
		if(ans==-1) puts("more");
		else printf("%d\n",ans);
	}
	return 0;
}



