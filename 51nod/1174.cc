#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 11111;

int n;
int q;
int nums[N] = {0};

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


int main() {
    input(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", nums + i);
    }
    RMQ::init();
    RMQ::init_pow();
    RMQ::initVAL(nums);
    RMQ::initRMQ();
    
    input(q);
    int a, b;
    while (q--) {
        scanf("%d%d", &a, &b);
        print(RMQ::query_max(a + 1, b + 1));
    }
    return 0;
}
