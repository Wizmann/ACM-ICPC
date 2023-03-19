#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 102400;

struct node {
    int value, nr;
    node(){}
    node(int ivalue, int inr): value(ivalue), nr(inr) {}

    friend bool operator > (const node& a, const node& b)
    {
        return a.value > b.value;
    }
};

int n, m;
node nodes[SIZE];
vector<int> g[SIZE];
map<int, int> mp;
int father[SIZE];
int size[SIZE];

int findfather(int x)
{
    if (x == father[x]) {
        return x;
    } else {
        return father[x] = findfather(father[x]);
    }
}

inline void do_union(int a, int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if (fa == fb) {
        return;
    }
    father[fa] = fb;
    size[fb] += size[fa];
}

llint solve()
{
    llint res = 0;
    vector<int> sz;
    sz.reserve(SIZE);
    for (int i = 1; i <= n; i++) {
        char visit[SIZE] = {0};
        sz.clear();
        for (auto iter = g[i].begin(); iter != g[i].end(); ++iter) {
            if (*iter > i) {
                break;
            }
            int g = findfather(*iter);
            if (!visit[g]) {
                sz.push_back(g);
                visit[g] = 1;
                res += (llint)size[g] * nodes[i].value;
            }
        }
        llint sumup = 0;
        for (int j = sz.size() - 2; j >= 0; j--) {
            sumup += size[sz[j + 1]];
            res += (llint)size[sz[j]] * sumup * nodes[i].value;
        }
        for (int j = 0; j < (int)sz.size(); j++) {
            do_union(i, sz[j]);
        }
    }
    return res;
}

int main()
{
    freopen("d.txt", "r", stdin);
    int a, b;
    input(n >> m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        nodes[i] = node(a, i);
        father[i] = i;
        size[i] = 1;
    }
    sort(nodes + 1, nodes + n + 1, greater<node>());
    for (int i = 1; i <= n; i++) {
        mp[nodes[i].nr] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        a = mp[a];
        b = mp[b];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    llint sum = solve();
    printf("%.5lf\n", double(sum) * 2 / n / (n - 1));
    return 0;
}

