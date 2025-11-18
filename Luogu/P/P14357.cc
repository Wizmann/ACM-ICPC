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

int main() {
    string s;
    input(s);

    string nums;
    for (auto c : s) {
        if ('0' <= c && c <= '9') {
            nums.push_back(c);
        }
    }

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    print(nums);

    return 0;
}

/*

^^^TEST^^^
5
-----
5
$$$TEST$$$

^^^TEST^^^
290es1q0
-----
92100
$$$TEST$$$

*/
