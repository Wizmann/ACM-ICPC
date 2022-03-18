#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

class KuhnMunkres {
public:
    KuhnMunkres(int size_) : \
            size(size_), g(size, vector<llint>(size)),
            matx(size, -1), maty(size, -1),
            lx(size), ly(size, -INF), pre(size) { /* pass */ }
    
    void addEdge(int u, int v, llint w) {
        assert(u < size && v < size);
        g[u][v] = max(g[u][v], w);
    };

    llint solve() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ly[i] = max(ly[i], g[j][i]);
            }
        }

        for (int i = 0; i < size; ++i) {
            bfs(i);
        }
        llint res = 0;
        for (int i = 0; i < size; ++i) {
            res += g[i][matx[i]]; 
        }
        return res;
    }

    int matchx(int x) {
        return g[x][matx[x]] > 0 ? matx[x] : -1;
    }
private:
    void bfs(int u) {
        vector<bool> visx(size);
        vector<bool> visy(size);
        vector<llint> slack(size, INFLL);

        q = queue<int>();
        q.push(u);
        visx[u] = true;
        while (true) {
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v = 0; v < size; ++v) {
                    if (!visy[v]) {
                        llint del = lx[u] + ly[v] - g[u][v];
                        if (del < slack[v]) {
                            pre[v] = u;
                            slack[v] = del;
                            if (!slack[v] && check(visx, visy, v)) {
                                return;
                            }
                        }
                    }
                }
            }

            llint a = INFLL;
            for (int i = 0; i < size; i++) {
                if (!visy[i]) {
                    a = min(a, slack[i]);
                }
            }
            for (int i = 0; i < size; i++) {
                if (visx[i]) {
                    lx[i] -= a;
                }
                if (visy[i]) {
                    ly[i] += a;
                } else {
                    slack[i] -= a;
                }
            }
            for (int i = 0; i < size; i++) {
                if (!visy[i] && !slack[i] && check(visx, visy, i)) {
                    return;
                }
            }
        }
    }

    bool check(vector<bool>& visx, vector<bool>& visy, int u) {
        visy[u] = 1;
        if (maty[u] != -1) {
            q.push(maty[u]);
            visx[maty[u]] = true;
            return false;
        }
        while (u != -1) {
            maty[u] = pre[u];
            swap(u, matx[pre[u]]);
        }
        return true;
    };

private:
    int size;
    vector<vector<llint>> g;
    vector<int> matx, maty;
    vector<llint> lx, ly; 
    vector<int> pre;
    queue<int> q;
};


int main() {
    int n, m, k;
    input(n, m, k);

    KuhnMunkres km(max(n, m));

    int a, b, c;
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &a, &b, &c);
        km.addEdge(a - 1, b - 1, c);
    }

    print(km.solve());

    for (int i = 0; i < n; i++) {
        printf("%d ", km.matchx(i) + 1);
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
2 2 3
1 1 100
1 2 1
2 1 1
-----
100
1 0
$$$TEST$$$

*/
