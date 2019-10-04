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

typedef long long llint;

const int SIZE = 88888;
const llint INF = 0x3f3f3f3f3f3f3f3f;

struct BITreeRMQ
{
    llint tree[SIZE],num[SIZE];
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
    llint query(int a,int b)
    {
        llint ans=num[b];
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

    void modify(int pos,llint val)
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

struct Node {
    int st, end, cost;

    bool operator < (const Node& other) const {
        if (st != other.st) {
            return st < other.st;
        } else {
            return end < other.end;
        }
    }
};

int main() {
    int n, m, e;
    scanf("%d%d%d", &n, &m, &e);
    {
        vector<Node> nodes;

        int st = m - 1;
        m = 1;
        e -= st;

        int a, b, c;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            Node cur;
            cur.st = max(1, a - st);
            cur.end = min(e, b - st);
            // print(cur.st << ' ' << cur.end);
            cur.cost = c;

            if (cur.end <= 0) {
                continue;
            }
            nodes.push_back(cur);
        }
        sort(nodes.begin(), nodes.end());
        
        BITreeRMQ bt;
        memset(bt.num, 0x3f, sizeof(bt.num));
        bt.init();

        for (int i = 0; i < nodes.size(); i++) {
            const Node& cur = nodes[i];
            if (cur.st == 1) {
                bt.modify(cur.end, cur.cost);
            } else {
                llint mini = bt.query(cur.st - 1, cur.end);
                bt.modify(cur.end, mini + cur.cost);
            }
        }
        llint res = bt.query(e, e);
        if (res >= INF) {
            printf("-1\n");
        } else {
            printf("%lld\n", res);
        }
    }

    return 0;
}
