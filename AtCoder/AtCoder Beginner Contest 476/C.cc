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
    int n;
    input(n);

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pq.push(x);
        while (pq.size() > 3) {
            pq.pop();
        }
        if (pq.size() >= 3) {
            printf("%d\n", pq.top());
        }
    }

    return 0;
}

/*

^^^TEST^^^
5
1 2 1 2 3
-----
1
1
2
$$$TEST$$$

^^^TEST^^^
10
1 1 1 3 2 5 4 3 6 5
-----
1
1
1
2
3
3
4
5
$$$TEST$$$

^^^TEST^^^
10
11 9 1 3 17 19 10 19 17 3
-----
1
3
9
11
11
17
17
17
$$$TEST$$$
*/
