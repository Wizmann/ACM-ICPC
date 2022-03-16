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

    void AddEdge(int from, int to) {
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



int main() {
    int n;
    input(n);

    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    int m;
    input(m);

    vector<int> ms(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &ms[i]);
    }

    HopcroftKarp hk(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(ns[i] - ms[j]) <= 1) {
                hk.AddEdge(i, j);
            }
        }
    }

    print(hk.match());

    return 0;
}

/*

^^^TEST^^^
4
1 4 6 2
5
5 1 5 7 9
-----
3
$$$TEST$$$

^^^TEST^^^
4
1 2 3 4
4
10 11 12 13
-----
0
$$$TEST$$$

^^^TEST^^^
5
1 1 1 1 1
3
1 2 3
-----
2
$$$TEST$$$

*/
