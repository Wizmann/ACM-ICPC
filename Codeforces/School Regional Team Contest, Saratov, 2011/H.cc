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


map<llint, int> mp;
vector<string> rmp;
map<int, set<int> > subs;
const llint MOD = 0xdeadbeefcafebabeLL;
const llint PRIME = 29;

void find_sub(const string& s, int idx) {
    int n = s.size();

    for (int i = 1; i < (1 << n); i++) {
        string sub;
        llint h = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sub.push_back(s[j]);
                h = (h * PRIME + s[j] - 'a' + 1) % MOD;
            }
        }
        if (sub.size() > 4) {
            continue;
        }
        if (mp.find(h) == mp.end()) {
            mp[h] = rmp.size();
            rmp.push_back(sub);
        }

        subs[mp[h]].insert(idx);
    }
}

int main() {
#ifndef __CPRUN__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    input(n);

    vector<string> ns(n);
    for (int i = 0; i < n; i++) {
        input(ns[i]);
    }

    for (int i = 0; i < n; i++) {
        find_sub(ns[i], i);
    }

    int m = mp.size();

    HopcroftKarp hk(m, n);

    for (const auto& kvlist : subs) {
        int key = kvlist.first;
        auto& sub = kvlist.second;

        for (auto idx : sub) {
            hk.addEdge(key, idx);
        }
    }

    int match = hk.match();
    if (match == n) {
        for (int i = 0; i < n; i++) {
            int x = hk.get_match_y(i);
            puts(rmp[x].c_str());
        }
    } else {
        puts("-1");
    }

    return 0;
}

/*

^^^TEST^^^
6
privet
spasibo
codeforces
java
marmelad
normalno
-----
6
$$$TEST$$$

^^^TEST^^^
5
aaa
aa
a
aaaa
aaaaa
-----
-1
$$$TEST$$$

*/
