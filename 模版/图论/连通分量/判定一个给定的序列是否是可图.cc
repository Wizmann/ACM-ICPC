/*
* Havel-Hakimi定理
    * 判定一个给定的序列是否是可图的。
    * 判定过程
      1. 对当前数列排序，使其呈递减
      2. 从S[2] 开始对其后S[1]个数字-1
      3. 一直循环直到当前序列出现负数（即不是可图的情况）或者当前序列全为0 （可图）时退出
*/


//Result:Wizmann    POJ 1236    Accepted    760 KB    16 ms    G++    1864 B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

vector<int> g[SIZE];
int n;
char instack[SIZE];
int low[SIZE];
int nr;
stack<int> st;
int dfn[SIZE],scc[SIZE],num[SIZE],sccnr=0;

void init()
{
    for(int i=0;i<SIZE;i++) g[i].clear();
    memset(instack,0,sizeof(instack));
    memset(scc,0,sizeof(scc));
    memset(num,0,sizeof(num));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    while(!st.empty()) st.pop();
    nr=1;sccnr=0;
}

void tarjan(int x)
{
    low[x]=dfn[x]=nr++;
    st.push(x);
    instack[x]=1;
    
    for(int i=0;i<(int)g[x].size();i++)
    {
        int next=g[x][i];
        if(!dfn[next])
        {
            tarjan(next);
            low[x]=min(low[x],low[next]);
        }
        else if(instack[next])
        {
            low[x]=min(low[x],dfn[next]);
        }
    }

    if(dfn[x]==low[x])
    {
        sccnr++;
        while(1)
        {
            int t=st.top();
            instack[t]=0;
            st.pop();
            scc[t]=sccnr;
            num[sccnr]++;
            if(t==x) break;
        }
    }
}

int out[SIZE],in[SIZE];

int main()
{
    freopen("input.txt","r",stdin);
    int tmp;
    while(input(n))
    {
        init();
        
        memset(out,0,sizeof(out));
        memset(in,0,sizeof(int));
        for(int i=0;i<n;i++)
        {
            while(1)
            {
                scanf("%d",&tmp);
                if(!tmp) break;
                g[i].push_back(--tmp);
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(!dfn[i]) tarjan(i);
        }

        for(int i=0;i<n;i++)
        {
            out[scc[i]]=g[i].size();
            for(int j=0;j<(int)g[i].size();j++)
            {
                int k=g[i][j];
                if(scc[i]!=scc[k]) in[scc[k]]++;
            }
        }

        
        int inz,outz;
        inz=outz=0;
        for(int i=1;i<=sccnr;i++)
        {
            if(!in[i]) inz++;
            if(!out[i]) outz++;
        }
        if(sccnr==1) printf("1\n0\n");
        else printf("%d\n%d\n",inz,max(inz,outz));
    }
    return 0;
}



