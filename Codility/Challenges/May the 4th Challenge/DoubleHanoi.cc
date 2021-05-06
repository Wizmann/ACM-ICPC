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


int solution(vector<int> &A, int L, int R) {
    sort(A.begin(), A.end());
    const int n = A.size();
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] == -1) {
            continue;
        }
        if (A[i] < L) {
            L = A[i];
            A[i] = -1;
            cnt++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] == -1) {
            continue;
        }
        if (A[i] > R) {
            R = A[i];
            A[i] = -1;
            cnt++;
        }
    }
    return cnt;
}
/*
int main() {
    vector<int> v1 = {2, 3, 3, 4};
    assert(solution(v1, 3, 1) == 3);

    vector<int> v2 = {1, 4, 5, 5};
    assert(solution(v2, 6, 4) == 4);

    vector<int> v3 = {5, 2, 5, 2};
    assert(solution(v3, 8, 1) == 4);

    vector<int> v4 = {1, 5, 5};
    assert(solution(v4, 2, 4) == 2);

    return 0;
}
*/
