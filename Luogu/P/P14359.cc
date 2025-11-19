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

int main() {
    int n, k;
    input(n, k);

    vector<int> ns(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
    }
    
    map<int, int> mp;
    mp[0] = 0;

    int maxi = 0;
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        pre ^= ns[i];
        // print(i, pre, ns[i]);
        int target = pre ^ k;

        if (mp.count(target)) {
            int u = mp[target] + 1;
            maxi = max(u, maxi);
        }

        mp[pre] = max(mp[pre], maxi);
    }

    print(maxi);

    return 0;
}

/*

^^^TEST^^^
4 2
2 1 0 3
-----
2
$$$TEST$$$

^^^TEST^^^
4 3
2 1 0 3
-----
2
$$$TEST$$$

^^^TEST^^^
4 0
2 1 0 3
-----
1
$$$TEST$$$

*/
