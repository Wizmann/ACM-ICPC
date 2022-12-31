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

template <typename T, class Compare=less<int> >
class BITreeRMQ {
public:
    BITreeRMQ() {}
    BITreeRMQ(int n_, const vector<T>& nums_) : n(n_), nums(nums_), tree(nums_) {
        assert((int)nums.size() == n);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < lowbit(i); j <<= 1) {
                tree[i] = cmp(tree[i], tree[i - j]);
            }
        }
    }

    T query(int a, int b) {
        T ans = nums[b];
        while (a != b) {
            for (b = b - 1; b - lowbit(b) >= a; b -= lowbit(b)) {
                ans = cmp(ans, tree[b]);
            }
            ans = cmp(ans, nums[b]);
        }
        return ans;
    }

    void modify(int pos, T val) {
        nums[pos] = val;
        for (int i = pos; i < n; i += lowbit(i)) {
            tree[i] = nums[i];
            for (int j = 1; j < lowbit(i); j <<= 1) {
                tree[i] = cmp(tree[i], tree[i - j]);
            }
        }
    }
private:
    T cmp(T a, T b) {
        return cmp_func(a, b)? a: b;
    }

    inline int lowbit(int x) {
        return x&(-x);
    }

    int n;
    vector<T> nums;
    vector<T> tree;
    Compare cmp_func = Compare();
};

vector<int> ans;

int main() {
    int n;
    input(n);
    vector<int> ns(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
    }

    ans = vector<int>(n + 1, INF);

    {
        BITreeRMQ<int> rmq1(n + 1, vector<int>(n + 1, INF));
        BITreeRMQ<int> rmq2(n + 1, vector<int>(n + 1, INF));

        for (int i = 1; i <= n; i++) {
            int pi = ns[i];
            int u1 = rmq1.query(1, pi) + pi + i;
            int u2 = rmq2.query(pi, n) - pi + i;
            ans[i] = min(ans[i], u1);
            ans[i] = min(ans[i], u2);

            rmq1.modify(pi, -pi - i);
            rmq2.modify(pi, pi - i);
        }
    }

    {
        BITreeRMQ<int> rmq1(n + 1, vector<int>(n + 1, INF));
        BITreeRMQ<int> rmq2(n + 1, vector<int>(n + 1, INF));

        for (int i = n; i >= 1; i--) {
            int pi = ns[i];
            int u1 = rmq1.query(1, pi) + pi - i;
            int u2 = rmq2.query(pi, n) - pi - i;
            ans[i] = min(ans[i], u1);
            ans[i] = min(ans[i], u2);

            rmq1.modify(pi, -pi + i);
            rmq2.modify(pi, pi + i);
        }

    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
4
3 2 4 1
-----
2 2 3 3 
$$$TEST$$$

^^^TEST^^^
7
1 2 3 4 5 6 7
-----
2 2 2 2 2 2 2 
$$$TEST$$$

^^^TEST^^^
16
12 10 7 14 8 3 11 13 2 5 6 16 4 1 15 9
-----
3 3 3 5 3 4 3 3 4 2 2 4 4 4 4 7 
$$$TEST$$$

*/
