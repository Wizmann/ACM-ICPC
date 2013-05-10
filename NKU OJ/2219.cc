//Result:Wizmann	2219	Accepted	GNU C++	2.34k	10 ms	2304 KB	2013-04-23 20:14:27
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int N = 4096;

int n,k;
int array[N];

namespace RMQ
{
    enum{RMQSIZE=17};
    int mini[N][RMQSIZE],maxi[N][RMQSIZE];
    int pow2[RMQSIZE];
    int tolog2[1<<RMQSIZE];

    int log2(int x)
    {
        return upper_bound(pow2,pow2+RMQSIZE,x)-pow2-1;
    }
    inline void init_pow()
    {
        for(int i=0;i<RMQSIZE;i++) pow2[i]=1<<i;
        for(int i=0;i<(1<<RMQSIZE);i++)
        {
            tolog2[i]=log2(i);
        }
    }

    inline void init()
    {
        memset(mini,0,sizeof(mini));
    }
    
    inline void initVAL(int val[])
    {
        for(int i=1;i<=n;i++)
        {
            mini[i][0]=maxi[i][0]=val[i];
        }
    }
    
    
    void initRMQ()
    {
        int m=tolog2[n];
        for(int i=1;i<=m;i++)
        {
            for(int j=n;j>=1;j--)
            {
                maxi[j][i]=maxi[j][i-1];
                mini[j][i]=mini[j][i-1];

                if(j+(1<<(i-1))<=n)
                {
                    mini[j][i]=min(mini[j][i],mini[j+(1<<(i-1))][i-1]);
                    maxi[j][i]=max(maxi[j][i],maxi[j+(1<<(i-1))][i-1]);
                }
            }
        }
    }
    inline int query_max(int l,int r)
    {
        int m=tolog2[r-l+1];
        return max(maxi[l][m],maxi[r-(1<<m)+1][m]);
    }
    inline int query_min(int l,int r)
    {
        int m=tolog2[r-l+1];
        return min(mini[l][m],mini[r-(1<<m)+1][m]);
    }
}


int main()
{
    while(input(n>>k))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",array+i);
        }
        RMQ::init();
        RMQ::init_pow();
        RMQ::initVAL(array);
        RMQ::initRMQ();

        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=n;j>=i;j--)
            {
                if(j-i+1 <= ans) break;
                else
                {
                    int mini = RMQ::query_min(i,j);
                    int maxi = RMQ::query_max(i,j);
                    //printf("(%d,%d) min:%d, max%d \n",i,j,mini,maxi);

                    if(maxi-mini <= k)
                    {
                        ans = max(ans, j-i+1);
                    }
                }
            }
        }
        print(ans);
    }
    return 0;
}

