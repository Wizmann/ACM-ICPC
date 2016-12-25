#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 55555;

inline int lowbit(int x) { return x&(-x); }

struct BIT_RMQ
{
    void init()
    {
        memset(bitree,0,sizeof(bitree));
        memset(num,0,sizeof(num));
    }

    int query(int a,int b)
    {
        int ans=num[b];
        while(1)
        {
            ans=max(ans,num[b]);
            if(a==b) break;
            else
            {
                b--;
                while(b-a>=lowbit(b))
                {
                    ans=max(ans,bitree[b]);
                    b-=lowbit(b);
                }
            }
        }
        return ans;
    }

    void modify(int pos,int val)
    {
        num[pos]=val;
        for(int i=pos;i<SIZE;i+=lowbit(i))
        {
            bitree[i]=max(val,bitree[i]);
            for(int j=1;j<lowbit(i);j<<=1)
            {
                bitree[i]=max(bitree[i],bitree[i-j]);
            }
        }
    }

    int bitree[SIZE];
    int num[SIZE];
};

int n, m;
BIT_RMQ bitrmq;

int main() {
    freopen("input.txt", "r", stdin);
    int x;
    input(n >> m);
    bitrmq.init();

    for (int i = 1; i <= n; i++) {
        input(x);
        bitrmq.modify(i, x);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &x);
        if (x <= bitrmq.num[1]) {
            continue;
        }
        int l = 1;
        int r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int maxi = bitrmq.query(1, mid);
            if (maxi >= x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (r == 0) {
            continue;
        }
        if (l > n) {
            continue;
        }
        int cur = bitrmq.num[r];
        bitrmq.modify(r, cur + 1);
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", bitrmq.num[i]);
    }
    return 0;
}
