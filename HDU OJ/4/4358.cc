//Result:2012-08-12 21:45:18	Accepted	4358	1140MS	15408K	3419 B	C++	Wizmann
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <deque>
#include <map>

//HDU开栈外挂
#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100

struct BIT
{
	int baum[SIZE];
	void init()
	{
		memset(baum,0,sizeof(baum));
	}
	inline int lowbit(int x)
	{
		return x&(-x);
	}
	
	void add(int x,int val)
	{
		while(x<SIZE)
		{
			baum[x]+=val;
			x+=lowbit(x);
		}
	}
	int sum(int x)
	{
		int res=0;
		while(x>0)
		{
			res+=baum[x];
			x-=lowbit(x);
		}
		return res;
	}
	int sum(int l,int r)
	{
		return sum(r)-sum(l-1);
	}
};

struct query
{
	int l,r,id;
	query(){}
	query(int il,int ir,int iid)
	{
		l=il;r=ir;id=iid;
	}
	friend bool operator < (const query& a,const query& b)
	{
		return a.r<b.r;
	}
};

int n,k,q;
int w[SIZE];
vector<int> pl[SIZE];
vector<int> g[SIZE];
int lson[SIZE],rson[SIZE],val[SIZE];
int cnt,ind;


//重要：将树转化为线性数组
void dfs(int now,int father)
{
	lson[now]=rson[now]=++ind;
	val[now]=w[now];
	for(int i=0;i<(int)g[now].size();i++)
	{
		int next=g[now][i];
		if(next!=father)
		{
			dfs(next,now);
			rson[now]=rson[next];
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("temp.ans","w",stdout);
	int T,a,b;
	BIT bit;
	query ask[SIZE];
	int ans[SIZE];
	map<int,int> mp;
	input(T);
	int cas=1;
	while(T--)
	{
		bit.init();//树状数组初始化
		cnt=ind=0;
		mp.clear();
		memset(ans,0,sizeof(ans));
		for(int i=0;i<SIZE;i++) g[i].clear();
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
			if(!mp[w[i]])
			{
				mp[w[i]]=++cnt;
				pl[cnt].clear();
			}
			w[i]=mp[w[i]];
			//离散化，权值的具体值在本题并没有意义
			//所以只需要区分开
		}
		for(int i=1;i<n;i++)
		{
			//建树
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		//使用DFS对树进行重编号，将树转化为线性数组
		//使任一非叶子节点的lson,rson值为一个连续区间
		dfs(1,-1);
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
			scanf("%d",&a);
			ask[i]=query(lson[a],rson[a],i);
			//离线处理，对query排序
		}
		sort(ask,ask+q);
		int ptr=0;
		for(int i=1;i<=n;i++)
		{
			//val[i]代表对于重编号后的i点代表的权值
			int v=val[i];
			pl[v].push_back(i);
			int sz=pl[v].size();//已经遍历了多少个v值
			if(sz>=k)//如果已经遍历了多于/等于k个v
			{
				if(sz==k)
				{
					//特殊情况，特判
					bit.add(pl[v][sz-k],1);//对于满足条件的右区间进行＋1操作
				}
				if(sz>k)
				{
					//我们现在只考虑一个v值的情况
					//若区间[a+1...i][a+2...i]...[b...i]符合sum(v,[x...i])==k的条件
					//则从i点向左查找，如果包含b,不包含a，说明有k个v点.
					//如果不包含a,b，则说明有不到k个点，不计入答案
					//如果同时包含a,b，则说明超过k个点，也不计入答案
	
					//于是将点(a)标记为-1,将点(b)标记为1，
					//所以对于一个区间[x...i]，如果sum([x...i])==1，则说明有k个v值
					//将此推广到多个v值同样成立
					bit.add(pl[v][sz-k-1],-2);//-1是将上一次的增加恢复原状，再-1是维护下一次的状态
					bit.add(pl[v][sz-k],1);
				}
			}

			while(ask[ptr].r==i)
			{
				int id=ask[ptr].id;
				//使用数状数组求区间和
				ans[id]=bit.sum(ask[ptr].l,ask[ptr].r);
				ptr++;
			}
		}
		printf("Case #%d:\n",cas++);
		for(int i=0;i<q;i++)
		{
			printf("%d\n",ans[i]);
		}
		if(T) puts("");
	}
	return 0;
}

