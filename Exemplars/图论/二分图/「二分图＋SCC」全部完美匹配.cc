//Result:wizmann	1904	Accepted	2588K	1329MS	G++	2832B	2012-10-05 19:06:57

/*
 * 2*N 个顶点的2分图，并且给了一个完美匹配(Perfect Matching)以及每个顶点可以连接的其他的顶点。
 * 要求是否可以确定某2个顶点连边后，其他 2*(N - 1) 个顶点的2分图是否可以构成完美匹配
 */

/*
 * 输入：
 * n ==> 人数
 * k a1...ak  k==>男士1喜欢的女士数目，编号为a1...ak
 * ...
 * ...
 * b1...bn 一个可行解，男士i喜欢的女士编号
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 4096
#define EDGE 220000

struct _link
{
	int val,next;
	_link(){}
	_link(int ival,int inext)
	{
		val=ival;next=inext;
	}
};

_link g[EDGE];
int head[NODE];
int n,ind;

inline void init()
{
	memset(head,-1,sizeof(head));
	ind=0;
}

inline void addEdge(int a,int b)
{
	g[ind]=_link(b,head[a]);
	head[a]=ind++;
}

int nextInt()
{
	char ch;
	int res=0;
	while((ch=getchar())==' ' || ch=='\n');
	res*=10;
	res+=ch-'0';
	while((ch=getchar())!=' ' && ch!='\n')
	{
		res*=10;res+=ch-'0';
	}
    return res;
}

inline void printInt(int x)
{
    if(x>=10) printInt(x/10);
    putchar(x%10+'0');
}


namespace SCC
{
	char instack[NODE];
	int low[NODE];
	int nr;
	stack<int> st;
	int dfn[NODE];
	int scc[NODE];
	int num[NODE];
	int sccnr;

	void init()
	{
		memset(instack,0,sizeof(instack));
		memset(dfn,0,sizeof(dfn));
		memset(scc,0,sizeof(scc));
		memset(num,0,sizeof(num));
		memset(low,0,sizeof(low));
		st=stack<int>();
		nr=1;sccnr=0;
	}

	void tarjan(int pos)
	{
		low[pos]=dfn[pos]=nr++;
		st.push(pos);
		instack[pos]=1;

		for(int i=head[pos];i!=-1;i=g[i].next)
		{
			int j=g[i].val;
			if(!dfn[j])
			{
				tarjan(j);
				low[pos]=min(low[pos],low[j]);
			}
			else if(instack[j])
			{
				low[pos]=min(low[pos],dfn[j]);
			}
		}

		if(dfn[pos]==low[pos])
		{
			sccnr++;
			while(1)
			{
				int t=st.top();
				instack[t]=0;
				st.pop();
				scc[t]=sccnr;
				num[sccnr]++;
				if(t==pos) break;
			}
		}
	}	
}

vector<int> ans[NODE];
char love[NODE];

void slove()
{
	for(int i=0;i<NODE;i++) ans[i].clear();
	for(int i=0;i<n*2;i++)
	{
		if(!SCC::dfn[i]) SCC::tarjan(i);
	}
	
	for(int i=n;i<n*2;i++)
	{
		ans[SCC::scc[i]].push_back(i);
	}
	for(int i=0;i<n;i++)
	{
		sort(ans[i].begin(),ans[i].end());
	}

	for(int i=0;i<n;i++)
	{
		memset(love,0,sizeof(love));
		vector<int> tmp;
		for(int j=head[i];j!=-1;j=g[j].next)
		{
			love[g[j].val]=1;
		}//Find man i love which woman
		for(int j=0;j<(int)ans[SCC::scc[i]].size();j++)
		{
			if(love[ans[SCC::scc[i]][j]])
			{
				tmp.push_back(ans[SCC::scc[i]][j]-n+1);
			}
		}
		//If a man and a womin in a SCC and the man loves the woman
		//It will work. :-)
		printInt(tmp.size());
		for(int j=0;j<(int)tmp.size();j++)
		{
			putchar(' ');
			printInt(tmp[j]);
		}
		putchar('\n');
	}
	
}
	
int main()
{
	int k,tmp;
	while(input(n))
	{
		init();
		SCC::init();
		for(int i=0;i<n;i++)
		{
			k=nextInt();
			while(k--)
			{
				tmp=nextInt();
				tmp--;
				addEdge(i,tmp+n);
			}
		}
		for(int i=0;i<n;i++)
		{
			tmp=nextInt();
			tmp--;
			addEdge(tmp+n,i);
		}
		slove();
	}
	return 0;
}

