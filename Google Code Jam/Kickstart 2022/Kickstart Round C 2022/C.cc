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

struct Ant {
    int id, p, d;

    bool operator < (const Ant& other) const {
        return p < other.p;
    }
};

struct Event {
    int id;
    int t;
};

int main() {
    int T;
    input(T);

    int n, l;
    for (int case_ = 0; case_ < T; case_++) {
        scanf("%d%d", &n, &l);

        vector<Ant> ants;
        vector<Ant> Lants;
        vector<Ant> Rants;
        int L = 0;
        int R = 0;
        int p, d;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p, &d);
            ants.push_back({i + 1, p, d});
            if (d == 0) {
                Lants.push_back({i + 1, p, d});
                L++;
            } else {
                Rants.push_back({i + 1, p, d});
                R++;
            }
        }

        sort(ants.begin(), ants.end());
        sort(Lants.begin(), Lants.end());
        sort(Rants.begin(), Rants.end());

        vector<Event> events;

        for (int i = 0; i < L; i++) {
            events.push_back({ants[i].id, Lants[i].p});
        }
        for (int i = 0; i < R; i++) {
            events.push_back({ants[i + L].id, l - Rants[i].p});
        }


        sort(events.begin(), events.end(),
            [](const Event& e1, const Event& e2) {
                if (e1.t != e2.t) {
                    return e1.t < e2.t;
                } else {
                    return e1.id < e2.id;
                }
            });

        /*
        for (const auto& e : events) {
            printf(" <%d,%d>", e.id, e.t);
        }
        puts("");
        */

        printf("Case #%d:", case_ + 1);
        for (const auto& e : events) {
            printf(" %d", e.id);
        }
        puts("");
    }

    return 0;
}

/*
^^^^^TEST^^^^
1
2 7
4 1
5 0
------
Case #1: 2 1
$$$TEST$$$$

^^^^^TEST^^^^
1
3 4
1 1
2 0
3 0
------
Case #1: 1 2 3
$$$TEST$$$$

^^^TEST^^^
3
1 5
1 1
2 7
4 1
5 0
4 10
8 0
2 1
6 1
4 0
-----
Case #1: 1
Case #2: 2 1
Case #3: 1 2 3 4
$$$TEST$$$

^^^TEST^^^
2
2 5
1 0
4 1
2 5
1 1
4 0
-----
Case #1: 1 2
Case #2: 1 2
$$$TEST$$$

*/
