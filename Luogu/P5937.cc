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

class DisjointSet {
public:
    DisjointSet(int n_) : n(n_) {
        // pass
    }

    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        father[fb] = fa;
    }

    bool same_set(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        return fa == fb;
    }

    int find_father(int x) {
        if (x == get(x)) {
            return x;
        }
        return father[x] = find_father(get(x));
    }
private:
    int get(int x) {
        if (!father.count(x)) {
            return x;
        }
        return father[x];
    }


private:
    int n;
    map<int, int> father;
};

int main() {
    int n;
    input(n);

    int q;
    input(q);

    DisjointSet ds(2 * n + 2);

    int ans = q;
    int a, b;
    char buffer[10];
    for (int i = 1; i <= q; i++) {
        scanf("%d%d%s", &a, &b, buffer);
        if (buffer[0] == 'e') {
            ds.make_union(a - 1, b);
            ds.make_union((a - 1) + n + 1, b + n + 1);
        } else {
            ds.make_union((a - 1) + n + 1, b);
            ds.make_union(a - 1, b + n + 1);
        }

        if (ds.same_set(a - 1, (a - 1) + n + 1) ||
                ds.same_set(b, b + n + 1)) {
            ans = i - 1;
            break;
        }
    }
    print(ans);

    return 0;
}

/*

^^^TEST^^^
10
5
1 2 even
3 4 odd
5 6 even
1 6 even
7 10 odd
-----
3
$$$TEST$$$

*/
