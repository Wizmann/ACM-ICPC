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

llint solve2(int* nums, int n, int x, int y) {
    // print(n, x, y);
    llint res = 0;
    multiset<int> st;

    int ptr = 0;
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
        while (!st.empty()) {
            int mini = *st.begin();
            int maxi = *st.rbegin();
            if (mini == x && maxi == y) {
                res += n - i;
                st.erase(st.find(nums[ptr]));
                ptr++;
            } else {
                break;
            }
        }
    }
    return res;
}

llint solve(int* nums, int n, int x, int y) {
    // print(n, x, y);
    llint res = 0;

    deque<int> st1;
    deque<int> st2;
    // multiset<int> st;

    int ptr = 0;
    for (int i = 0; i < n; i++) {
        while (!st1.empty() && *st1.begin() < ptr) {
            st1.pop_front();
        }
        while (!st1.empty() && nums[i] <= nums[*st1.rbegin()]) {
            st1.pop_back();
        }
        st1.push_back(i);
        
        while (!st2.empty() && *st2.begin() < ptr) {
            st2.pop_front();
        }
        while (!st2.empty() && nums[i] >= nums[*st2.rbegin()]) {
            st2.pop_back();
        }
        st2.push_back(i);

        // st.insert(nums[i]);

        while (ptr <= i) {
            while (!st1.empty() && *st1.begin() < ptr) {
                st1.pop_front();
            }
            while (!st2.empty() && *st2.begin() < ptr) {
                st2.pop_front();
            }
            int mini = nums[*st1.begin()];
            int maxi = nums[*st2.begin()];
            // assert(mini == *st.begin());
            // assert(maxi == *st.rbegin());
            // print(i, mini, maxi);
            if (mini == x && maxi == y) {
                res += n - i;
                // st.erase(st.find(nums[ptr]));
                ptr++;
            } else {
                break;
            }
        }
    }
    return res;
}

int main() {
    int n, x, y;
    input(n, x, y);

    swap(x, y);

    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    int l = -1;
    int r = 0;

    llint res = 0;
    for (int i = 0; i <= n; i++) {
        int cur = (i == n)? INF: ns[i];

        if (x <= cur && cur <= y) {
            if (l == -1) {
                l = i;
            }
            r = i;
        } else {
            if (l != -1) {
                res += solve(ns.data() + l, r - l + 1, x, y);
            }
            l = -1;
        }
    }
    print(res);

    return 0;
}

/*

^^^TEST^^^
4 3 1
1 2 3 1
-----
4
$$$TEST$$$

^^^TEST^^^
5 2 1
1 3 2 4 1
-----
0
$$$TEST$$$

^^^TEST^^^
5 1 1
1 1 1 1 1
-----
15
$$$TEST$$$

^^^TEST^^^
10 8 1
2 7 1 8 2 8 1 8 2 8
-----
36
$$$TEST$$$

*/
