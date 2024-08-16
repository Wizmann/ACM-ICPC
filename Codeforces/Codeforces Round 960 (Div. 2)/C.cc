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

int main() {
    int T;
    input(T);

    while (T--) {
        input(n);
        ns.resize(n);

        llint tot1 = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }


        for (int op = 0; op < 2; op++) {
            map<int, int> mp;
            int maxi = 0;
            for (int i = 0; i < n; i++) {
                mp[ns[i]]++;
                tot1 += ns[i];
                if (mp[ns[i]] >= 2) {
                    maxi = max(maxi, ns[i]);
                }
                ns[i] = maxi;
            }
        }

        llint tot2 = 0;
        for (int i = 0; i < n; i++) {
            tot2 += ns[i];
        }

        for (int i = 0; i < n; i++) {
            tot1 += tot2;
            tot2 -= ns[n - i - 1];
        }

        print(tot1);
    }

    return 0;
}

/*

^^^TEST^^^
4
1
1
3
2 2 3
4
2 1 1 2
4
4 4 4 4
-----
1
13
9
40
$$$TEST$$$

^^^TEST^^^
1
4
1 1 2 2
------------
13
$$$TEST$$$

*/
