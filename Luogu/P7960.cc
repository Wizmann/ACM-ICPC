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

struct Context {
    uint64_t size;
};

vector<int> nums;
vector<bool> bitmap;

const int MAXI = 10000006;

void fill_bitmap(int x) {
    int a = x;
    while (a < MAXI) {
        bitmap[a] = false;
        a += x;
    }
}

void init()
{
    bitmap = vector<bool>(MAXI, true);

    nums.reserve(123456);
    nums.push_back(7);
    fill_bitmap(7);

    for (int i = 1; i < 7; i++) {
        int m = nums.size();
        int prefix = 1;
        for (int j = 0; j < i; j++) {
            prefix *= 10;
        }
        for (int j = 1; j < 10; j++) {
            if (j != 7) {
                for (int k = 0; k < m; k++) {
                    nums.push_back(nums[k] + prefix * j);
                    fill_bitmap(nums[k] + prefix * j);
                }
            }
        }

        for (int j = 0; j < prefix; j++) {
            nums.push_back(7 * prefix + j);
            fill_bitmap(7 * prefix + j);
        }
    }
    nums.clear();
    for (int i = 0; i < MAXI; i++) {
        if (bitmap[i]) {
            nums.push_back(i);
        }
    }
}

int main() {
    init();

    int T;
    input(T);

    int x;
    while (T--) {
        scanf("%d", &x);

        auto iter = lower_bound(nums.begin(), nums.end(), x);
        if (*iter != x) {
            puts("-1");
        } else {
            printf("%d\n", *(++iter));
        }
    }

    return 0;
}

/*
 *
^^^TEST^^^
4
6
33
69
300
--------
8
36
80
-1
$$$TEST$$$

^^^TEST^^^
1
10000000
--------
-1
$$$TEST$$$

^^^TEST^^^
5
90
99
106
114
169
--------
92
100
109
-1
180
$$$TEST$$$

*/
