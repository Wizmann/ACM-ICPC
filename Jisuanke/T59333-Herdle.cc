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
const int ALPHA = 26;

string answer[N];
string guess[N];

int cnt[ALPHA + 123];

int main() {
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < N; i++) {
        cin >> answer[i];
        for(int j = 0; j < N; j++) {
            cnt[answer[i][j] - 'A']++;
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> guess[i];
    }

    int green = 0;
    int yellow = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (guess[i][j] == answer[i][j]) {
                green++;
                cnt[guess[i][j] - 'A']--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (guess[i][j] == answer[i][j]) {
                continue;
            }

            if (cnt[guess[i][j] - 'A']) {
                yellow++;
                cnt[guess[i][j] - 'A']--;
            }
        }
    }

    print(green);
    print(yellow);

    return 0;
}

/*

^^^TEST^^^
COW
SAY
MOO
WIN
THE
IOI
-----
1
1
$$$TEST$$$

^^^TEST^^^
AAA
BBB
CCC
AYY
AAA
ZZZ
-----
1
2
$$$TEST$$$

*/
