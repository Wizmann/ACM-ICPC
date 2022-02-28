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

int game(const vector<int>& A, const vector<int>& B) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (A[i] > B[j]) {
                a++;
            } else if (A[i] < B[j]) {
                b++;
            }
        }
    }

    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else {
        return 0;
    }
}

bool do_check(const vector<int>& A, const vector<int>& B, const vector<int>& C) {
    int v1 = game(A, B);
    int v2 = game(B, C);
    int v3 = game(C, A);

    return v1 && v2 && v3 && v1 == v2 && v2 == v3;
}

bool check() {
    vector<int> A(4, 0);
    vector<int> B(4, 0);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 4; i++) {
        scanf("%d", &B[i]);
    }

    for (int a1 = 1; a1 <= 10; a1++) {
    for (int a2 = 1; a2 <= 10; a2++) {
    for (int a3 = 1; a3 <= 10; a3++) {
    for (int a4 = 1; a4 <= 10; a4++) {
        vector<int> C = {a1, a2, a3, a4};
        if (do_check(A, B, C)) {
            return true;
        }
    }
    }
    }
    }

    return false;
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        bool flag = check();
        puts(flag ? "yes" : "no");
    }

    return 0;
}

/*

^^^TEST^^^
3
4 5 6 7 2 4 5 10
2 2 2 2 1 1 1 1
1 1 1 1 2 2 2 2
-----
yes
no
no
$$$TEST$$$

*/
