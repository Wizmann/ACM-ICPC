// Result: 6107500   Mar 22, 2014 7:40:50 PM    Wizmann  E - Strictly Positive Matrix    GNU C++0x  Accepted     546 ms  33000 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 2048;

struct node
{
    int val,next;
    node(){}
    node(int ival,int inext)
    {
        val=ival;
        next=inext;
    }
};

char instack[SIZE];//是否在栈中
int low[SIZE];//所有节点的最小标号
int nr=1;//时间编号
stack<int> st;
int dfn[SIZE];//时间戳
int scc[SIZE];//标明每一个点属于哪个SCC中
int num[SIZE];//每一个SCC中包含多少元素
int sccnr=0;//强连通分量编号

int head[SIZE];
node g[SIZE * SIZE];
int n;

int ind=0;//临接链表指针


//时间复杂度O(n+m)

inline void add_edge(int a,int b)
{
    g[ind]=node(b,head[a]);
    head[a]=ind;
    ind++;
}

void init()
{
    ind=0;
    memset(head,-1,sizeof(head));
    memset(g,0,sizeof(g));
    
    memset(instack,0,sizeof(instack));
    memset(dfn,0,sizeof(dfn));
    memset(scc,0,sizeof(scc));
    memset(num,0,sizeof(num));
    memset(low,0,sizeof(low));
    
    st = stack<int>();
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

int main()
{
    freopen("input.txt", "r", stdin);
    int u;
    input(n);

    init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &u);
            if (!u) continue;
            add_edge(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    puts(sccnr == 1? "YES": "NO");

    return 0;
}

