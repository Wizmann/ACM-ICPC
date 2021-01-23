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

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int SIZE = 1111;

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

const int LOGN = 32;
BIT<int> bits[LOGN];

int main() {
    int n, q;
    input(n, q);

    for (int i = 0; i < LOGN; i++) {
        bits[i] = BIT<int>(n + 1);
    }

    vector<int> ns(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
        for (int j = 0; j < 31; j++) {
            int b = ns[i] & (1 << j);
            bits[j].add(i, (b ? 1 : 0));
        }
    }

    int t, x, y;
    while (q--) {
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            int u = ns[x];
            int v = u ^ y;
            for (int j = 0; j < 31; j++) {
                int pre = u & (1 << j);
                int cur = v & (1 << j);
                int diff = (pre ? 1 : 0) - (cur ? 1 : 0);
                bits[j].add(x, diff);
            }
        } else {
            int res = 0;
            for (int j = 0; j < 31; j++) {
                int cur = bits[j].sum(x, y);
                if (cur % 2) {
                    res |= (1 << j);
                }
            }
            printf("%d\n", res);
        }
    }

    return 0;
}

/*
^^^TEST^^^
3 4
1 2 3
2 1 3
2 2 3
1 2 3
2 2 3
---
0
1
2
$$$TEST$$$

^^^TEST^^^
10 10
0 5 3 4 7 0 0 0 1 0
1 10 7
2 8 9
2 3 6
2 1 6
2 1 10
1 9 4
1 6 1
1 6 3
1 1 7
2 3 5
---
1
0
5
3
0
$$$TEST$$$
*/
