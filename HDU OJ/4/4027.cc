#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

#include <cassert>

typedef long long llint;

int log2(int x) {
    assert(x != 0);
    return (x > 1) ? (1 + log2(x >> 1)) : 0;
}

const int INF = 0x3f3f3f3f;

class SegTree {
public:
    const int UNKNOWN = -INF;

    SegTree(const vector<llint>& ns) {
        assert(log2(2) == 1);
        assert(log2(1) == 0);

        n = ns.size();
        N = 1 << (log2(n) + 1);
        assert(N > n);

        rangeL = vector<int>(N * 2, -1);
        rangeR = vector<int>(N * 2, -1);

        values = vector<llint>(N * 2, 0);

        for (int i = 0; i < N; i++) {
            rangeL[N + i] = rangeR[N + i] = i;
        }

        for (int i = 0; i < n; i++) {
            values[N + i] = ns[i];
        }

        for (int i = N - 1; i > 0; i--) {
            rangeL[i] = rangeL[left(i)];
            rangeR[i] = rangeR[right(i)];
            pushUp(i);
        }
    }

    void attack(int l, int r)
    {
        do_attack(1, l, r);
    }

    llint query(int l, int r) {
        return do_query(1, l, r);
    }
private:
    void pushUp(int x) {
        assert(x < N);
        values[x] = values[left(x)] + values[right(x)];
    }

    void do_attack(int cur, int l, int r) {
        assert(cur < 2 * N);

        if (cur >= N) {
            values[cur] = sqrt(values[cur]);
            return;
        }

        if (rangeR[cur] - rangeL[cur] + 1 == values[cur]) {
            return;
        }

        int m = rangeR[left(cur)];
        if (m >= l) {
            do_attack(left(cur), l, min(r, m));
        }
        if (m + 1 <= r) {
            do_attack(right(cur), max(l, m + 1), r);
        }
        pushUp(cur);
    }

    llint do_query(int cur, int l, int r) {
        assert(cur < 2 * N);
        if (rangeL[cur] == l && rangeR[cur] == r) {
            return values[cur];
        }

        assert(rangeL[cur] <= l && r <= rangeR[cur]);

        assert(cur < N);
        int m = rangeR[left(cur)];
        assert(m >= 0);

        llint res = 0;
        if (m >= l) {
            res += do_query(left(cur), l, min(r, m));
        }
        if (m + 1 <= r) {
            res += do_query(right(cur), max(l, m + 1), r);
        }
        return res;
    }
private:
    int left(int x) { 
        return x * 2;
    }
    int right(int x) {
        return x * 2 + 1;
    }
    int parent(int x) {
        return x / 2;
    }

    vector<int> rangeL;
    vector<int> rangeR;

    vector<llint> values;

    int n;
    int N;
};

int main() {
    int n;
    int case_ = 0;
    while (input(n)) {
        vector<llint> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &ns[i]);
        }
        SegTree st(ns);

        int q;
        input(q);

        printf("Case #%d:", ++case_);
        puts("");

        int a, b, c;
        while (q--) {
            scanf("%d%d%d", &a, &b, &c);
            b--; c--;
            if (b > c) {
                swap(b, c);
            }
            if (a == 0) {
                st.attack(b, c);
                /*
                for (int i = 0; i < n; i++) {
                    printf("%lld ", st.query(i, i));
                }
                puts("");
                */
            } else {
                llint res = st.query(b, c);
                printf("%lld\n", res);
            }
        }
        puts("");
    }
    return 0;
}
