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

class HopcroftKarp {
public:
    HopcroftKarp(int n1_, int n2_): n1(n1_), n2(n2_) {
        g.resize(n1);
        mx.resize(n1);
        dsx.resize(n1);
        my.resize(n2);
        dsy.resize(n2);
        visited.resize(n1 + n2);
    }

    void addEdge(int from, int to) {
        g[from].push_back(to);
    }

    int match() {
        int ans = 0;
        for (int i = 0; i < n1; i++) {
            mx[i] = -1;
        }
        for (int i = 0; i < n2; i++) {
            my[i] = -1;
        }

        while (bfs()) {
            fill(visited.begin(), visited.end(), false);
            for (int i = 0; i < n1; i++) {
                if (mx[i] == -1 && dfs(i)) {
                    ans++;
                }
            }
        }
        return ans;
    }

    int get_match_x(int x) const {
        return mx[x];
    }

    int get_match_y(int y) const {
        return my[y];
    }
private:
    bool bfs(){
        fill(dsx.begin(), dsx.end(), -1);
        fill(dsy.begin(), dsy.end(), -1);
        depth = INF;

        queue<int> q;
        
        for (int i = 0; i < n1; i++) {
            if(mx[i] == -1) {
                q.push(i);
                dsx[i] = 0;
            }
        }

        while (!q.empty()) {
            int x = q.front();
            if(dsx[x] > depth) {
                break;
            }
            
            for (auto y: g[x]) {
                if (dsy[y] == -1){
                    dsy[y] = dsx[x] + 1;
                    if(my[y] == -1) {
                        depth = dsy[y];
                    } else {
                        dsx[my[y]] = dsy[y] + 1;
                        q.push(my[y]);
                    }
                }
            }
            q.pop();
        }
        return depth != INF;
    }

    bool dfs(int x) {
        for (auto next: g[x]) {
            if (!visited[next] && dsy[next] == dsx[x] + 1) {
                visited[next] = true;
                if (my[next] != -1 && dsy[next] == depth) {
                    continue;
                }
                if (my[next] == -1 || dfs(my[next])){
                    my[next] = x;
                    mx[x] = next;
                    return true;
                }

            }
        }
        return false;
    }
private:
    int n1, n2;
    int depth;
    vector<int> mx, my;
    vector<int> dsx, dsy;
    vector<bool> visited;
    vector<vector<int> > g;
};

struct Edge {
    int a, b, cost;
};

int main() {
    int n, m;
    input(n, m);

    vector<Edge> edges;

    int a, b, c;
    int maxi = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({a - 1, b - 1, c});

        maxi = max(maxi, c);
    }

    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
        return e1.cost < e2.cost;
    });

    int l = 0;
    int r = maxi;

    while (l <= r) {
        int mid = (l + r) / 2;

        HopcroftKarp hk(n, n);
        for (int i = 0; i < m; i++) {
            if (edges[i].cost <= mid) {
                hk.addEdge(edges[i].a, edges[i].b);
            } else {
                break;
            }
        }
        // print(mid, hk.match());

        if (hk.match() == n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (l > maxi) {
        puts("-1");
    } else {
        print(l);
    }

    return 0;
}

/*

^^^TEST^^^
3 5
1 2 1
2 3 2
3 3 3
2 1 4
2 2 5
-----
4
$$$TEST$$$

*/
