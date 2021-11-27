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

const int SIZE = 212345;

class DisjointSet {
public:
    DisjointSet(int n_): n(n_) {
        father.resize(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }
    
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        } else {
            return father[x] = find_father(father[x]);
        }
    }
    
    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        
        father[fa] = fb;
    }
    
    bool is_same_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        
        return fa == fb;
    }
private:
    int n;
    vector<int> father;
};

int n, m;
vector<int> g[SIZE];

int main() {
    input(n, m);

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    DisjointSet ds(n + 1);

    vector<int> res;
    int pre = 0;
    for (int i = n; i >= 1; i--) {
        int cur = pre + 1;
        for (const auto& nxt : g[i]) {
            if (nxt <= i) {
                continue;
            }
            if (!ds.is_same_union(i, nxt)) {
                ds.make_union(i, nxt);
                cur--;
            }
        }
        res.push_back(pre);
        pre = cur;
    }
    reverse(res.begin(), res.end());
    for (auto num : res) {
        printf("%d\n", num);
    }

    return 0;
}

/*

^^^TEST^^^
6 7
1 2
1 4
1 5
2 4
2 3
3 5
3 6
-----
1
2
3
2
1
0
$$$TEST$$$

^^^TEST^^^
8 7
7 8
3 4
5 6
5 7
5 8
6 7
6 8
-----
3
2
2
1
1
1
1
0
$$$TEST$$$

*/
