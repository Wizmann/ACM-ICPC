//Result:   2014-05-27 17:49:56 Accepted    4831    562MS   1292K   5373 B  C++ Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define mpii(a, b) make_pair<int, int>(int(a), int(b))

const int SIZE = 10240;
const int QUERY = 128;
const int INF = 1 << 30;

struct Node {
    int type;
    int pos, hot;
    Node(){}
    Node(int itype, int ipos, int ihot): type(itype), pos(ipos), hot(ihot){}
};

struct Query {
    int type;
    int a, b;
    Query() {}
    Query(int itype, int ia, int ib): type(itype), a(ia), b(ib){}
};

inline int lowbit(int x)
{
    return x&(-x);
}

struct BIT//点更新，区间查询
{
    int baum[SIZE];
    inline void init()
    {
        memset(baum,0,sizeof(baum));
    }
    void add(int x,int val)
    {
        // print("ADD " << x << ' ' << val);
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

Node nodes[SIZE];
Query querys[QUERY];
vector<int> g[SIZE];
pair<int, int> cnc[SIZE];
char double_check[SIZE];
int hot[SIZE + QUERY];
int idx;
map<int, int> mp;
set<int> st;
int n, q;
BIT bit;

void init()
{
    idx = 0;
    bit.init();
    mp.clear();
    st.clear();
    memset(double_check, 0, sizeof(double_check));
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
    }
}

void intcvt()
{
    sort(hot, hot + idx);
    for (int i = 0; i < idx; i++) {
        mp[hot[i]] = i + 1;
    }
}

void solve()
{
    for (int i = 0; i < n; i++) {
        if (nodes[i].type != 0) {
            continue;
        }
        int a = i - 1, b = i + 1;
        int disa = INF, disb = INF;
        int hota = -INF, hotb = -INF;
        while (a >= 0 && nodes[a].type != 1) { a--; }
        if (a >= 0) {
            disa = abs(nodes[a].pos - nodes[i].pos);
            hota = nodes[a].hot;
        }
        
        while (b < n && nodes[b].type != 1) { b++; }
        if (b < n) {
            disb = abs(nodes[b].pos - nodes[i].pos);
            hotb = nodes[b].hot;
        }

        if (disa < disb) {
            nodes[i].hot = hota;
            //print("ACCESS " << a << ' ' << i);
            g[a].push_back(i);
        } else if (disb < disa) {
            nodes[i].hot = hotb;
            g[b].push_back(i);
            //print("ACCESS " << b << ' ' << i);
        } else if (disa != INF && disb != INF && disa == disb) {
            nodes[i].hot = max(hota, hotb);
            g[a].push_back(i);
            g[b].push_back(i);
            //print("ACCESS " << a << ' ' << i);
            //print("ACCESS " << b << ' ' << i);
            double_check[i] = 1;
            cnc[i] = mpii(a, b);
        } else {
            // ASSERT_ERROR
            // print(disa << ' ' << disb);
            while(1) {}
        }
    }
    
    for (int i = 0; i < n; i++) {
        bit.add(mp[nodes[i].hot], 1);
    }
    for (int i = 0; i < q; i++) {
        if (querys[i].type == 0) {
            printf("%d\n", bit.sum(mp[querys[i].a]));
        } else {
            int now = querys[i].a;
            if (nodes[now].type == 0) {
                continue;
            }
            bit.add(mp[nodes[now].hot], -1);
            nodes[now].hot = querys[i].b;
            bit.add(mp[nodes[now].hot], 1);
            for (int j = 0; j < (int)g[now].size(); j++) {
                int u = g[now][j];
                assert(nodes[u].type == 0);
                if (!double_check[u]) {
                    bit.add(mp[nodes[u].hot], -1);
                    nodes[u].hot = nodes[now].hot;
                    bit.add(mp[nodes[u].hot], 1);
                } else {
                    int a = cnc[u].first;
                    int b = cnc[u].second;
                    int c = max(nodes[a].hot, nodes[b].hot);
                    bit.add(mp[nodes[u].hot], -1);
                    nodes[u].hot = c;
                    bit.add(mp[nodes[u].hot], 1);
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T, cas = 1;
    char cmd[10];
    int a, b;
    input(T);
    while (T--) {
        input(n);
        init();
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            nodes[i] = Node(b == 0? 0: 1, a, b);
            if (b && st.find(b) == st.end()) {
                st.insert(b);
                hot[idx++] = b;
            }
        }
        input(q);
        for (int i = 0; i < q; i++) {
            scanf("%s", cmd);
            if (*cmd == 'Q') {
                scanf("%d", &b);
                querys[i] = Query(0, b, -1);
            } else {
                scanf("%d%d", &a, &b);
                querys[i] = Query(1, a, b);
            }

            if (st.find(b) == st.end()) {
                st.insert(b);
                hot[idx++] = b;
            }
        }
        intcvt();
        printf("Case #%d:\n", cas++);
        solve();
    }
    return 0;
}

