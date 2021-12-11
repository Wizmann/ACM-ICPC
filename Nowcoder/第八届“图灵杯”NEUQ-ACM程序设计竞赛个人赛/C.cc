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

int n;
vector<int> ns;

llint solve() {
    int pre = -INF;
    int cnt = 0;
    llint res = 0;
    for (int i = 0; i < n; i++) {
        if (ns[i] >= pre) {
            cnt++;
        } else {
            res += 1LL * cnt * (cnt + 1) / 2;
            cnt = 1;
        }
        pre = ns[i];
    }
    return res;
}

int main() {
    input(n);
    ns.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    map<int, int> mp;
    
    for (int num : ns) {
        mp[num] = -1;
    }

    int cnt = 1;
    for (auto& p: mp) {
        p.second = cnt++;
    }

    for (int i = 0; i < n; i++) {
        ns[i] = mp[ns[i]];
    }
    n++;
    ns.push_back(-INF);

    printf("%lld", solve());

    return 0;
}

/*

^^^TEST^^^
5
1 2 3 4 5
-----
15
$$$TEST$$$

*/

