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
    int n, T;
    input(n, T);

    map<llint, int> mp;
    vector<llint> score(n + 1, 0);

    mp[0] = n;

    int a, b;
    for (int i = 0; i < T; i++) {
        scanf("%d%d", &a, &b);
        llint pre = score[a];
        score[a] += b;
        llint cur = score[a];

        mp[pre] -= 1;
        if (mp[pre] == 0) {
            mp.erase(mp.find(pre));
        }
        mp[cur]++;
        printf("%d\n", (int)mp.size());
    }
    return 0;
}

/*

^^^TEST^^^
3 4
1 10
3 20
2 10
2 10
-----
2
3
2
2
$$$TEST$$$

^^^TEST^^^
1 3
1 3
1 4
1 3
-----
1
1
1
$$$TEST$$$

*/
