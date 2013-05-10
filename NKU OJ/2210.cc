//Result:Wizmann	2210	Accepted	GNU C++	1.49k	0 ms	1248 KB	2013-04-20 17:05:37
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 10;
const int INF = 1<<29;

int father[SIZE];
char cnc[SIZE][SIZE];
int n,ans;

void dfs(int now)
{
    if(now==n)
    {
        set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(father[i]);
            //printf("%d ",father[i]);
        }
        //puts("");
        ans=min(ans,(int)st.size());
    }
    else
    {
        father[now]=now;
        dfs(now+1);
        for(int i=0;i<now;i++)
        {
            if(father[i]==i)
            {
                bool flag = true;
                for(int j=0;j<now;j++)
                {
                    if(father[j]==i)
                    {
                        if(cnc[now][j])
                        {
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag)
                {
                    father[now]=i;
                    dfs(now+1);
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int a;
    while(input(n))
    {
        ans=INF;
        memset(cnc,0,sizeof(cnc));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&a);
                cnc[i][j]=a;
            }
        }
        dfs(0);
        print(ans);
    }
    return 0;
}

