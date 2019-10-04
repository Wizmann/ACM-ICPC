#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 55555;
const int INF = 0x3f3f3f3f;

struct BITreeRMQ
{
    int tree[SIZE],num[SIZE];
    inline int lowbit(int x)
    {
        return x&(-x);
    }
    void init()
    {
        for(int i=1;i<SIZE;i++)
        {
            tree[i]=num[i];
            for(int j=1;j<lowbit(i);j<<=1)
            {
                tree[i]=min(tree[i],tree[i-j]);
            }
        }
    }
    int query(int a,int b)
    {
        int ans=num[b];
        while(a != b)
        {
            for (b = b - 1; b - lowbit(b) >= a; b -= lowbit(b))
            {
                ans=min(ans,tree[b]);
            }
            ans = min(ans, num[b]);
        }
        return ans;
    }

    void modify(int pos,int val)
    {
        num[pos]=min(num[pos], val);
        for(int i=pos;i<SIZE;i+=lowbit(i))
        {
            tree[i]=num[i];
            for(int j=1;j<lowbit(i);j<<=1)
            {
                tree[i]=min(tree[i],tree[i-j]);
            }
        }
    }
};

typedef pair<int, int> pii;

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        
        BITreeRMQ bt;
        memset(bt.num, INF, sizeof(bt.num));
        bt.init();

        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            if (a == 1) {
                bt.modify(b, 1);
            } else {
                int mini = bt.query(a, b);
                bt.modify(b, mini + 1);
            }
        }
        printf("%d\n", bt.query(n, n));
    }

    return 0;
}
