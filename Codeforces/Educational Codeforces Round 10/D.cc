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

typedef long long llint;

const int SIZE = 422222;

struct Seg {
    int first;
    int second;
    int nr;
};

int n;
map<int, int> mp;
vector<Seg> segs;

inline int lowbit(int x) { return x&(-x); }

struct BIT//点更新，区间查询
{
    int baum[SIZE];
    inline void init()
    {
        memset(baum,0,sizeof(baum));
    }
    void add(int x,int val)
    {
        while(x<SIZE)
        {
            baum[x]+=val;
            x+=lowbit(x);
        }
    }
    int sum(int x)
    {
        int res=0;
        while(x>0)
        {
            res+=baum[x];
            x-=lowbit(x);
        }
        return res;
    }
    int sum(int a,int b)//查询区间和
    {
        return sum(b)-sum(a-1);
    }
};

int main() {
    int a, b;
    input(n);
    segs.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        segs[i] = {a, b, i};
        mp.insert({a, -1});
        mp.insert({b, -1});
    }

    int idx = 1;
    for (auto& p: mp) {
        p.second = idx++;
    }

    for (auto& seg: segs) {
        seg.first = mp[seg.first];
        seg.second = mp[seg.second];
    }

    sort(segs.begin(), segs.end(),
            [](const Seg& pa, const Seg& pb) {
                if (pa.second != pb.second) {
                    return pa.second < pb.second;
                }
                return pa.first > pb.first;
            });

    BIT bitree;
    bitree.init();

    vector<int> ans(n, 0);
    for (auto seg: segs) {
        a = seg.first;
        b = seg.second;
        int idx = seg.nr;

        ans[idx] = bitree.sum(a, b);
        bitree.add(a, 1);
    }
    for (auto num: ans) {
        printf("%d\n", num);
    }
    return 0;
}
