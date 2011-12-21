//Result:1499 	Accepted	21MS	296K	G++	1413B	2011-11-29 22:18:42	Wizmann 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>

#define pb push_back

using namespace std;

vector<int> g[110];
int top[110];

int main()
{
    int n,ask;
    while(scanf("%d%d",&n,&ask)!=EOF)
    {
        if(n==0&&ask==0) break;
        for(int i=0;i<=n;i++) g[i].clear();
        memset(top,0,sizeof(top));
        int a,b;
        int flag=0;
        while(ask--)
        {
            scanf("%d%d",&a,&b);
            g[a].pb(b);
            top[b]++;
            if(a==b) flag=1;
        }
        
        if(flag) printf("Yes\n");
        else
        {
            for(int t=1;t<=n;t++)
            {
                int i;
                for(i=1;i<=n;i++)
                {
                    flag=1;
                    if(top[i]==0)
                    {
                        flag=0;
                        top[i]=-1;
                        break;
                    }
                }
                
                if(flag)
                {
                    printf("Yes\n");
                    flag=-1;
                    break;
                }
                for(int j=0;j<(int)g[i].size();j++)
                {
                    top[g[i][j]]--;
                }
            }
            if(flag!=-1) printf("No\n");
        }        
    }
    return 0;
}
     
