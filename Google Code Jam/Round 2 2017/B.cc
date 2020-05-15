#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

struct Ticket {
    int p, b, idx;
};

bool do_check(
        int n, int c, int m, int train,
        const vector<vector<Ticket> >& g, int& promo)
{
    int rem = 0;
    promo = 0;
    for (int i = n; i > 0; i--) {
        int cur = g[i].size();
        if (cur < train) {
            rem -= train - cur;
            rem = max(rem, 0);
        } else {
            promo += cur - train;
            rem += cur - train;
        }
    }
    return rem == 0;
}


vector<int> solve(int n, int c, int m, const vector<Ticket>& tickets) {
    vector<vector<Ticket> > g(n + 1);
    vector<int> ts(c + 1, 0);
    int maxt = 0;
    for (const auto& ticket : tickets) {
        g[ticket.p].push_back(ticket);
        ts[ticket.b]++;
        maxt = max(maxt, ts[ticket.b]);
    }

    int l = maxt;
    int r = m; // one ticket, one train

    int promo = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        bool check = do_check(n, c, m, mid, g, promo);
        if (check) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    bool check = do_check(n, c, m, l, g, promo);
    assert(check);
    return { l, promo };
}

int main()
{
    // test();
    int T;
    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        int n, c, m;
        input(n, c, m);

        vector<Ticket> tickets(m);

        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            tickets[i] = {a, b, i};
        }

        auto p = solve(n, c, m, tickets);
        printf("Case #%d: %d %d\n", case_ + 1, p[0], p[1]);
    }

    return 0;
}

