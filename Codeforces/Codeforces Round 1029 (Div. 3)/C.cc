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
map<int, int> mp;

int solve() {
    int cnt = 0;
    map<int, int> head;

    vector<int> zeros;

    for (int i = n - 1; i >= 0; i--) {
        int cur = ns[i];
        mp[cur]--;

        if (mp[cur] == 0) {
            zeros.push_back(cur);
        }

        head[cur]++;

        if (head.size() == mp.size()) {
            cnt++;
            head.clear();

            for (auto z : zeros) {
                mp.erase(mp.find(z));
            }
            zeros.clear();
        }
    }
    return cnt;
}

int main() {
    int T;
    input(T);

    while (T--) {
        scanf("%d", &n);

        ns = vector<int>(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        mp.clear();
        for (int i = 0; i < n; i++) {
            mp[ns[i]]++;
        }

        printf("%d\n", solve());
    }

    return 0;
}

/*

^^^TEST^^^
8
6
1 2 2 3 1 5
8
1 2 1 3 2 1 3 2
5
5 4 3 2 1
10
5 8 7 5 8 5 7 8 10 9
3
1 2 2
9
3 3 1 4 3 2 4 1 2
6
4 5 4 5 6 4
8
1 2 1 2 1 2 1 2
-----
2
3
1
3
1
3
3
4
$$$TEST$$$

*/
