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

struct Machine {
    int x, y;

    int val() const {
        return 500 * x + 2 * y;
    }

    bool operator < (const Machine& other) const {
        return val() < other.val();
    }
};

const int NX = 1444;
const int NY = 111;

vector<Machine> tasks;
vector<int> machines[NY];

int main() {
    int n, m;

    int x, y;
    while (input(n, m)) {
        for (int i = 0; i < NY; i++) {
            machines[i].clear();
        }
        tasks.clear();

        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            machines[y].push_back(x);
        }

        for (int i = 0; i < NY; i++) {
            sort(machines[i].begin(), machines[i].end());
        }

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            tasks.push_back({x, y});
        }

        sort(tasks.begin(), tasks.end(),
            [](const Machine& a, const Machine& b) {
                if (a.x != b.x) { return a.x > b.x; }
                return a.y > b.y;
            });

        int cnt = 0;
        llint res = 0;

        for (const auto& task : tasks) {
            for (int i = task.y; i < NY; i++) {
                auto iter = lower_bound(machines[i].begin(), machines[i].end(), task.x);
                if (iter != machines[i].end()) {
                    res += task.x * 500 + 2 * task.y;
                    cnt++;
                    machines[i].erase(iter);
                    break;
                }
            }
        }

        printf("%d %lld\n", cnt, res);
    }

    return 0;
}

/*

^^^TEST^^^
1 2
100 3
100 2
100 1
1 2
100 3
100 2
100 1
-----
1 50004
1 50004
$$$TEST$$$

*/
