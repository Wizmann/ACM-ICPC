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

int n, m;
vector<vector<int> > S;

int main() {
    input(n, m);
    S.resize(n);
    for (int i = 0; i < n; i++) {
        S[i] = vector<int>(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &S[i][j]);
        }
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mp[S[i][j]] = -1;
        }
    }

    int idx = 1;
    for (auto& p : mp) {
        p.second = idx++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            S[i][j] = mp[S[i][j]];
        }
    }

    BIT<int> bitree(idx);
    for (int i = 1; i < idx; i++) {
        bitree.add(i, 1);
    }

    llint res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = S[i][j];
            bitree.add(u, -1);
        }

        for (int j = 0; j < m; j++) {
            int u = S[i][j];
            res += bitree.sum(1, u) + (j + 1) * (n - i - 1);
            // print(bitree.sum(1, u) + (j + 1) * (n - i - 1));
        }
        // puts("--");
    }

    print(res);

    return 0;
}

/*

^^^TEST^^^
3 2
1 3
2 8
4 6
-----
12
$$$TEST$$$

^^^TEST^^^
1 1
306
-----
0
$$$TEST$$$

^^^TEST^^^
4 4
155374934 164163676 576823355 954291757
797829355 404011431 353195922 138996221
191890310 782177068 818008580 384836991
160449218 545531545 840594328 501899080
-----
102
$$$TEST$$$

*/
