// 求解最大团问题
// 从1~100里面求一个最大子集，使得子集中的任意两个数之和不为完全平方数

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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

const int N = 101;
const int N_DOUBLE = 201;

char squares[N_DOUBLE];

void init() {
    memset(squares, 0, sizeof(squares));
    for (int i = 0; i * i < N_DOUBLE; i++) {
        squares[i * i] = 1;
    }
}

double Rand() { return (double)rand() / RAND_MAX; }

void get_next(const vector<bool>& now, vector<bool>& nxt, double t) {
    nxt = now;
    assert(nxt.size() == N);
    for (int i = 0; i < 20; i++) {
        int idx = int(Rand() * N) % N + 1;
        nxt[idx] = nxt[idx] ^ bool(Rand() < 0.5 * t);
    }
}

int calc(const vector<bool>& bitmap) {
    int n = bitmap.size();
    assert(n == N);
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (bitmap[i] == 0) {
            continue;
        }
        cnt++;
        for (int j = i + 1; j < n; j++) {
            if (bitmap[j] == 0) {
                continue;
            }
            assert(i + j < N_DOUBLE);
            if (squares[i + j]) {
                return 0;
            }
        }
    }
    return cnt;
}

int maxi = 0;
vector<bool> ans;

void simulateAnneal(int round) {
    double t = 1;
    vector<bool> now(N, false);
    vector<bool> nxt(N, false);
    int now_value = 0;

    while (t >= 1. / RAND_MAX) {
        for (int i = 0; i < 20; /* pass */) {
            get_next(now, nxt, t);
            int nxt_value = calc(nxt);
            if (nxt_value == 0) {
                continue;
            }
            i++;

            if (nxt_value > maxi) {
                maxi = nxt_value;
                ans = nxt;
                printf("[%d] -> %d\n", round, maxi);
                for (int j = 1; j < N; j++) {
                    if (ans[j]) {
                        printf("%d ", j);
                    }
                }
                puts("");
            }
            // 这里是求极大值的方法；若要求极小值，接受新解的条件是`delta <= 0 || exp(-delta /t) > Rand()`
            double delta = nxt_value - now_value;
            if (delta >= 0 || exp(delta / t) > Rand()) {
                now = nxt;
                now_value = nxt_value;
            }
        }
        t *= 0.99;
    }
}

int main() {
    init();

    // srand(0);
    srand(time(nullptr));

    for (int i = 0; i < 19; i++) {
        simulateAnneal(i);
    }
    return 0;
}


