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

const int SIZE = 333;

int n;
vector<int> As;
vector<int> g[SIZE];
vector<pair<llint, llint> > res[SIZE];

const llint BASE1 = 10000000000000LL;
const llint BASE2 = 10000000000LL;

void spfa(int src) {
    res[src].resize(SIZE);
    vector<bool> visited(SIZE, false);
    queue<int> q;
    vector<llint> dis(SIZE, INFLL);

    q.push(src);
    visited[src] = 0;
    dis[src] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visited[cur] = false;

        for (auto nxt : g[cur]) {
            llint cost = 1LL * dis[cur] + BASE1 + (BASE2 - As[nxt]);

            if (cost < dis[nxt]) {
                dis[nxt] = cost;
                if (!visited[nxt]) {
                    q.push(nxt);
                    visited[nxt] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dis[i] >= INFLL) {
            res[src][i] = {-1, -1};
        } else {
            llint a = dis[i] / BASE1;
            llint b = dis[i] % BASE1;

            b = BASE2 * a - b + As[src];

            res[src][i] = {a, b};
        }
    }
}

int main() {
    input(n);

    As.resize(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &As[i]);
    }

    string s;
    for (int i = 0; i < n; i++) {
        input(s);
        for (int j = 0; j < n; j++) {
            if (s[j] == 'Y') {
                g[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        spfa(i);
    }

    int q;
    input(q);

    int a, b;
    while (q--) {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        auto r = res[a][b];
        if (r.first == -1) {
            puts("Impossible");
        } else {
            printf("%lld %lld\n", r.first, r.second);
        }
    }

    return 0;
}

/*

^^^TEST^^^
5
30 50 70 20 60
NYYNN
NNYNN
NNNYY
YNNNN
YNNNN
3
1 3
3 1
4 5
-----
1 100
2 160
3 180
$$$TEST$$$

^^^TEST^^^
2
100 100
NN
NN
1
1 2
-----
Impossible
$$$TEST$$$

*/
