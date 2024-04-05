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

bool check(const vector<int>& ns, int len, int diff) {
    int n = ns.size();
    deque<int> st1, st2;

    for (int i = 0; i < n; i++) {
        int cur = ns[i];

        while (!st1.empty()) {
            if (i - *st1.begin() >= len) {
                st1.pop_front();
            } else {
                break;
            }
        }

        while (!st1.empty()) {
            if (cur >= ns[*st1.rbegin()]) {
                st1.pop_back();
            } else {
                break;
            }
        }
        st1.push_back(i);

        while (!st2.empty()) {
            if (i - *st2.begin() >= len) {
                st2.pop_front();
            } else {
                break;
            }
        }

        while (!st2.empty()) {
            if (cur <= ns[*st2.rbegin()]) {
                st2.pop_back();
            } else {
                break;
            }
        }
        st2.push_back(i);

        int maxi = ns[*st1.begin()];
        int mini = ns[*st2.begin()];

        if (i + 1 >= len && maxi - mini <= diff) {
            return true;
        }
    }
    return false;
}

int main() {
    int k, n;
    input(k, n);

    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    int l = 1;
    int r = n;

    while (l <= r) {
        int m = (l + r) / 2;

        if (check(ns, m, k)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    print(r);

    return 0;
}

/*
^^^TEST^^^
3 3
9 1 9
-----
1
$$$TEST$$$

^^^TEST^^^
3 9
5 1 3 5 8 6 6 9 10
-----
4
$$$TEST$$$

*/
