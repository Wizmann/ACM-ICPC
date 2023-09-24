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

const int N = 3;
const int NN = N * N;

vector<int> ns(NN);
vector<int> perm(NN);

const vector<vector<int> > rules = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

bool check() {
    vector<int> ms(NN, -1);
    for (int i = 0; i < NN; i++) {
        ms[perm[i]] = ns[perm[i]];
        for (const auto& rule : rules) {
            int value = -1;
            bool flag1 = false;
            bool flag2 = false;
            for (int j = 0; j < 3; j++) {
                int a = ms[rule[j]];
                if (a == -1) {
                    flag1 = true;
                    continue;
                }
                if (value == -1) {
                    value = a;
                } else if (value == a) {
                    flag2 = true;
                }
            }
            if (flag1 && flag2) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    for (int i = 0; i < NN; i++) {
        scanf("%d", &ns[i]);
    }

    for (int i = 0; i < NN; i++) {
        perm[i] = i;
    }

    int tot = 0;
    int legal = 0;
    do {
        if (check()) {
            legal++;
        }
        tot++;
    } while (next_permutation(perm.begin(), perm.end()));

    // print(legal, tot);
    printf("%.8lf\n", 1.0 * legal / tot);

    return 0;
}

/*

^^^TEST^^^
3 1 9
2 5 6
2 7 1
-----
0.666666666666666666666666666667
$$$TEST$$$


^^^TEST^^^
7 7 6
8 6 8
7 7 6
-----
0.004982363315696649029982363316
$$$TEST$$$

^^^TEST^^^
3 6 7
1 9 7
5 7 5
-----
0.4
$$$TEST$$$
*/
