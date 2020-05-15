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

int solve(const vector<int>& ns, int p) {
    vector<int> rems(p);
    for (auto num : ns) {
        rems[num % p]++;
    }

    int res = 0;
    res += rems[0];
    if (p == 2) {
        res += (rems[1] + 1) / 2;
    } else if (p == 3) {
        int u = min(rems[1], rems[2]);
        res += u;
        rems[1] -= u;
        rems[2] -= u;

        int v = max(rems[1], rems[2]);
        res += (v + 2) / 3;
    } else if (p == 4) {
        int u = min(rems[1], rems[3]);
        res += u;
        rems[1] -= u;
        rems[3] -= u;

        res += rems[2] / 2;
        rems[2] %= 2;

        int v = max(rems[1], rems[3]);

        if (rems[2]) {
            if (v >= 2) {
                res++;
                rems[2] -= 1;
                v -= 2;
            } else {
                res++;
                rems[2] -= 1;
                v = 0;
            }
        }
        res += (v + 3) / 4;
    } else {
        assert(false);
    }
    return res;
}

int judge(const vector<int>& ns, int p) {
    int cur = 0;
    int res = 0;
    for (auto num : ns) {
        if (cur == 0) {
            res++;
        }
        while (cur < num) {
            cur += p;
        }
        cur -= num;
    }
    return res;
}

int brute_force(vector<int> ns, int p) {
    int res = 0;
    sort(ns.begin(), ns.end());
    do {
        /*
        for (auto num : ns) {
            printf("%d ", num);
        }
        puts("");
        */
        res = max(res, judge(ns, p));
    } while (next_permutation(ns.begin(), ns.end()));
    return res;
}

void test() {
    assert(solve({2, 4, 5, 7, 4}, 4) == 4);
    assert(judge({6, 8, 4, 4, 7}, 3) == 3);
    assert(brute_force({4, 7, 8, 6, 4}, 3) == 3);
    for (int i = 0; i < 10; i++) {
        int n = 8;
        srand(i);
        vector<int> ns(n);
        for (int j = 0; j < n; j++) {
            ns[j] = rand() % 10 + 1;
        }
        for (int p = 2; p <= 4; p++) {
            print(p);
            for (auto num : ns) {
                printf("%d ", num);
            }
            puts("");
            int a = solve(ns, p);
            int b = brute_force(ns, p);
            print(a, b);
            puts("--");
            assert(a == b);
        }
    }
}

int main()
{
    // test();
    int T;
    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        int n, p;
        input(n, p);
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        printf("Case #%d: %d\n", case_ + 1, solve(ns, p));
    }

    return 0;
}

