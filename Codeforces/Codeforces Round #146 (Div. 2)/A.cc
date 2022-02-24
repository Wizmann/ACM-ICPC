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
    std::string name;
    input(name);

    sort(name.begin(), name.end());

    auto iter = std::unique(name.begin(), name.end());

    int num = std::distance(name.begin(), iter);

    if (num % 2 == 0) {
        puts("CHAT WITH HER!");
    } else {
        puts("IGNORE HIM!");
    }

    return 0;
}

/*
^^^^TEST^^^
wjmzbmr
-------
CHAT WITH HER!
$$$TEST$$$


^^^^TEST^^^
xiaodao
-------
IGNORE HIM!
$$$TEST$$$

^^^^TEST^^^
sevenkplus
-------
CHAT WITH HER!
$$$TEST$$$

*/
