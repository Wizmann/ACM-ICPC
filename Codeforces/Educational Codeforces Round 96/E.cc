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

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int SIZE = 212345;

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



const int ALPHA = 30;

deque<int> g[ALPHA];




llint solve(const string& s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        g[c].push_back(i);
    }

    BIT<int> bit(n + 1);

    int p = 0;
    llint step = 0;

    for (int i = n - 1; i >= 0; i--) {
        int c = s[i] - 'a';
        int q = *g[c].begin();
        int actual = p - bit.sum(1, q + 1) + q;
        bit.add(q + 1, 1);
        g[c].pop_front();

        // print(actual, p, s[i]);
        step += actual - p;
        p++;
    }
    return step;
}

int main() {
    int n;
    input(n);

    string s;
    input(s);
    
    print(solve(s));

    return 0;
}

/*

^^^TEST^^^
5
aaaza
---
2
$$$TEST$$$

^^^TEST^^^
6
cbaabc
---
0
$$$TEST$$$

^^^TEST^^^
9
icpcsguru
---
30
$$$TEST$$$

*/
