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

const int INF = 0x3f3f3f3f;

int solution(vector<int> &A) {
    deque<int> st;
    A.push_back(0);
    int n = A.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        int cur = A[i];
        while (!st.empty() && A[st.back()] > cur) {
            int pre = st.back();
            st.pop_back();
            int l = st.empty() ? 0: st.back() + 1;
            res = max(res, min(A[pre], i - l));
        }
        st.push_back(i);
    }
    return res;
}
