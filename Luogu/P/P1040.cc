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

const int N = 33;

vector<int> ns;
llint dp[N][N];
vector<int> preorder;

llint dfs1(int l, int r) {
    assert(l <= r);
    if (dp[l][r] != 0) {
        return dp[l][r];
    }

    if (l == r) {
        return 1;
    }

    if (r - l == 1) {
        return ns[l];
    }

    llint maxi = 0;

    for (int i = l; i < r; i++) {
        llint v1 = dfs1(l, i);
        llint v2 = dfs1(i + 1, r);

        llint v = v1 * v2 + ns[i];
        maxi = max(maxi, v);
    }

    // print(l, r, maxi);

    return dp[l][r] = maxi;
}

void dfs2(int l, int r, llint maxi) {
    assert(l <= r);
    if (l == r) {
        assert(maxi == 1);
        return;
    }

    if (r - l == 1) {
        preorder.push_back(l);
        assert(maxi == ns[l]);
        return;
    }

    for (int i = l; i < r; i++) {
        llint v1 = dfs1(l, i);
        llint v2 = dfs1(i + 1, r);

        llint v = v1 * v2 + ns[i];
        if (v == maxi) {
            preorder.push_back(i);
            dfs2(l, i, v1);
            dfs2(i + 1, r, v2);
            return;
        }
    }
    assert(false);
}

int main() {
    int n;
    input(n);

    ns.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }


    llint maxi = dfs1(0, n);
    print(maxi);

    dfs2(0, n, maxi);

    for (auto item : preorder) {
        printf("%d ", item + 1);
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
5
5 7 1 2 10
-----
145
3 1 2 4 5
$$$TEST$$$

*/
