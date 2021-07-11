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

int lowbit(int x) { return x & (-x); }

template <typename T>
class BIT
{
public:
    BIT() {}
    BIT(int n_) : n(n_), nums(n + 1) {}

    void add(int x, T val) {
        while(x < n) {
            nums[x] += val;
            x += lowbit(x);
        }
    }

    T sum(int x) {
        T res = 0;
        while(x > 0) {
            res += nums[x];
            x -= lowbit(x);
        }
        return res;
    }

    T sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int n;
    vector<T> nums;
};

BIT<llint> bit1;
BIT<llint> bit2;
BIT<llint> bit3;
BIT<llint> bit4;

int calc(llint x, llint p) {
    x -= x % p;
    int cnt = 0;
    while (x && x % p == 0) {
        x /= p;
        cnt++;
    }
    return cnt;
}

int calc2(llint x, llint p) {
    int ans = calc(x, p);
    x += x % p;
    int cnt = 0;
    while (x && x % p == 0) {
        x /= p;
        cnt++;
    }
    return max(ans, cnt);
}

int V(llint x, llint p) {
    int cnt = 0;
    while (x && x % p == 0) {
        x /= p;
        cnt++;
    }
    return cnt;
}

void do_change(int pos, llint pre, llint cur, llint p) {
    int cnt0 = V(pre, p);
    int cnt1 = V(cur, p);

    if (pre > 0) {
        if (cnt0 == 0) {
            if (pre > p) {
                bit2.add(pos, -calc(pre, p));
                bit3.add(pos, -1);
                bit4.add(pos, -calc2(pre, p));
            }
        } else {
            bit1.add(pos, -cnt0);
        }
    }

    if (cnt1 == 0) {
        if (cur > p) {
            bit2.add(pos, calc(cur, p));
            bit3.add(pos, 1);
            bit4.add(pos, calc2(cur, p));
        }
    } else {
        bit1.add(pos, cnt1);
        // print(">>", pos, bit1.sum(pos, pos));
    }
}

llint do_query(llint s, llint l, llint r, int p) {
    llint tot = 0;
    tot += bit1.sum(l, r) * s;
    if (s % 2 != 0) {
        tot += bit2.sum(l, r) + bit3.sum(l, r) * V(s, p);
    } else {
        tot += bit4.sum(l, r) + bit3.sum(l, r) * V(s, p);
    }
    // print(l, r, bit1.sum(l, r), bit2.sum(l, r), bit4.sum(l, r), V(s, p) + 1);
    // print("---");
    return tot;
}

int main() {
    int T;
    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        int n, q, p;
        input(n, q, p);

        vector<llint> nums(n + 1);

        bit1 = BIT<llint>(n + 1);
        bit2 = BIT<llint>(n + 1);
        bit3 = BIT<llint>(n + 1);
        bit4 = BIT<llint>(n + 1);

        llint a, b, c, s;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a);
            do_change(i, -1, a, p);
            nums[i] = a;
        }

        /*
        for (int i = 1; i <= n; i++) {
            printf("%lld ", bit1.sum(i, i));
        }
        puts("");
        */

        vector<llint> ans;

        int tp;
        for (int i = 0; i < q; i++) {
            scanf("%d", &tp);
            if (tp == 1) {
                scanf("%lld%lld", &b, &c);
                do_change(b, nums[b], c, p);
                nums[b] = c;
            } else {
                scanf("%lld%lld%lld", &s, &b, &c);
                ans.push_back(do_query(s, b, c, p));
            }
        }

        printf("Case #%d:", case_ + 1);
        for (auto num : ans) {
            printf(" %lld", num);
        }
        puts("");
    }

    return 0;
}

/*

^^^TEST^^^
1
10 10 17
905506628 8955371851 406344403 8560799840 4044584373 5717030221 7876518204 1768525034 6294927788 7069831349
2 68 2 3
2 82 8 9
1 5 378147956796123175
2 56 3 8
2 8 1 4
1 7 818676528851554679
2 91 2 9
2 56 2 10
2 92 4 10
2 47 7 7
------
Case #1: 4 3 6 4 9 10 8 1
$$$TEST$$$

^^^TEST^^^
2
5 5 2
16 94 62 67 91
2 3 3 4
1 1 69
2 3 1 4
2 1 1 1
2 3 2 2
5 5 5
1 2 3 4 5
2 1 1 5
1 3 98
2 3 2 4
1 5 3
2 2 1 5
-----
Case #1: 4 9 2 3
Case #2: 1 1 1
$$$TEST$$$

^^^TEST^^^
1
10 10 3
78 88 48 9 98 33 94 39 65 58
2 3 9 10
2 3 3 4
2 3 7 8
2 3 2 8
2 3 4 4
2 3 4 10
2 3 4 6
2 3 3 8
2 3 7 10
2 3 1 10
------
Case #1: 5 9 5 21 6 21 11 19 10 29
$$$TEST$$$

^^^TEST^^^
1
10 6 2
347699780 6897178455 1506345925 4108487605 8487557771 8208126216 1842574875 6451617159 798942926 2933706486
2 12 4 4
2 12 5 5
2 12 6 6
2 12 7 7
2 12 8 8
2 12 4 8
-----
Case #1: 4 4 36 4 5 53
$$$TEST$$$

^^^TEST^^^
1
10 10 2
347699780 6897178455 1506345925 4108487605 8487557771 8208126216 1842574875 6451617159 798942926 2933706486 
2 133 2 4
2 12 4 8
2 2 9 10
2 253 1 2
1 9 906768264777327254
2 88 4 8
2 63 2 3
2 179 3 5
1 10 602015396621005421
2 8 2 10
------
Case #1: 5 53 4 507 285 3 5 69
$$$TEST$$$$

*/
