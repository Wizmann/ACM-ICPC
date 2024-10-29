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

const int SIZE = 123456;

vector<int> mp;

int main() {
    int n;
    input(n);

    mp = vector<int>(SIZE, 0);

    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        mp[x]++;
    }

    llint pre = 0;
    for (int i = 0; i < SIZE; i++) {
        int delta = min(1LL * mp[i], pre);
        pre -= delta;
        pre += mp[i];
    }

    print(pre);

    return 0;
}

/*

^^^TEST^^^
5
1 2 3 1 2
-----
2
$$$TEST$$$

^^^TEST^^^
10
136 136 136 2417 136 136 2417 136 136 136
-----
8
$$$TEST$$$

*/
