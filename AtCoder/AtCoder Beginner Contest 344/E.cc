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
#include <list>
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
    list<int> lst;
    map<int, list<int>::iterator> mp;

    int n;
    input(n);

    int a, b, c;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        lst.push_back(a);
        mp[a] = --lst.end();
    }

    int q;
    input(q);
    while (q--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d", &b, &c);
            auto iter = mp[b];
            mp[c] = lst.insert(++iter, c);
        } else if (a == 2) {
            scanf("%d", &b);
            auto iter = mp[b];
            lst.erase(iter);
            mp.erase(mp.find(b));
        }
    }

    for (auto num : lst) {
        printf("%d ", num);
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
4
2 1 4 3
4
2 1
1 4 5
2 2
1 5 1
-----
4 5 1 3
$$$TEST$$$


^^^TEST^^^
6
3 1 4 5 9 2
7
2 5
1 3 5
1 9 7
2 9
2 3
1 2 3
2 4
-----
5 1 7 2 3
$$$TEST$$$

*/
