#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 200020;
const int INF = 0x3f3f3f3f;

struct BiTreeRMQ
{
    int baum[SIZE],num[SIZE];
    inline int lowbit(int x)
    {
        return x&(-x);
    }
    void init()
    {
        for(int i=1;i<SIZE;i++)
        {
            baum[i]=num[i];
            for(int j=1;j<lowbit(i);j<<=1)
            {
                baum[i]=min(baum[i],baum[i-j]);
            }
        }
    }
    int query(int a,int b)
    {
        int ans=num[b];
        while(1)
        {
            ans=min(ans,num[b]);
            if(a==b) break;
            else
            {
                for (b = b - 1; b - a >=lowbit(b); b -= lowbit(b))
                {
                    ans=min(ans,baum[b]);
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
            baum[i]=num[i];
            for(int j=1;j<lowbit(i);j<<=1)
            {
                baum[i]=min(baum[i],baum[i-j]);
            }
        }
    }
};

int main() {
    int n;
    input(n);
    BiTreeRMQ tree;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tree.num[i]);
        tree.num[i] = tree.num[i];
    }
    tree.init();
    
    int m;
    int a, b;
    input(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        print(tree.query(a + 1, b + 1));
    }

    return 0;
}
