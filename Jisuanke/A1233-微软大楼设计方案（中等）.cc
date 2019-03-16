#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 222222;
const int LOGSIZE = 18;

int pow2[LOGSIZE];
int tolog2[1<<LOGSIZE];

int log2(int x)
{
    return upper_bound(pow2,pow2+LOGSIZE,x)-pow2-1;
}

inline void init_pow()
{
    for(int i=0;i<LOGSIZE;i++) pow2[i]=1<<i;
    for(int i=0;i<(1<<LOGSIZE);i++)
    {
        tolog2[i]=log2(i);
    }
}

struct RMQ
{
    int n;
    int mini[SIZE][LOGSIZE];
    int maxi[SIZE][LOGSIZE];

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
};

int nums[SIZE];
RMQ rmq;

int main() {
    freopen("input.txt", "r", stdin);
    int n, k, m;
    input(n >> k);

    init_pow();

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    rmq.n = n;
    rmq.init();
    rmq.initVAL(nums);
    rmq.initRMQ();


    input(m);
    vector<pair<int, int> > points;

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        a--;
        points.push_back({a, b});
    }
    sort(points.begin(), points.end());

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            auto pa = points[i];
            auto pb = points[j];

            int mv = k + 1;
            if (pa.first == pb.first) {
                mv = abs(pa.second - pb.second);
            } else if (pa.first + 1 == pb.first) {
                mv = abs(pa.second - pb.second) + 1;
            } else {
                int mini = rmq.query_min(pa.first + 1, pb.first - 1);
                if (mini >= max(pa.second, pb.second)) {
                    mv = pb.first - pa.first + abs(pa.second - pb.second);
                } else if (mini <= min(pa.second, pb.second)) {
                    mv = pb.first - pa.first + pa.second - mini + pb.second - mini;
                } else {
                    mv = pb.first - pa.first + abs(pa.second - mini) + abs(pb.second - mini);
                }
            }
            ans += (mv <= k);
        }
    }
    print(ans);
    return 0;
}

