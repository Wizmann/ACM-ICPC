#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <queue>
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
    int T;
    input(T);

    while (T--) {
        int n;
        input(n);
        priority_queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i + 1);
        }

        vector<pair<int, int> > ans;
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            ans.push_back({a, b});
            q.push((a + b + 1) / 2);
        }
        print(q.top());
        for (const auto& p: ans) {
            printf("%d %d\n", p.first, p.second);
        }
    }

    return 0;
}

/*
^^^TEST^^^
1
4
----
2
2 4
3 3
3 1
$$$TEST$$$
*/
