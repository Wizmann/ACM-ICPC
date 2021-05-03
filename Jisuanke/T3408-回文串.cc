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

#define input(x) cin >> x
#define print(x) cout << x << endl

const int N = 12345;

char buffer[N];

bool dfs(int l, int r, bool flag) {
    if (l >= r) {
        return true;
    }
    if (buffer[l] == buffer[r]) {
        return dfs(l + 1, r - 1, flag);
    } else if (flag == false) {
        return dfs(l + 1, r - 1, true);
    }
    return false;
}

bool solve(int n) {
    return dfs(0, n - 1, false);
}

int main() {
    int T;
    input(T);

    while (T--) {
        scanf("%s", buffer);
        int n = strlen(buffer);

        puts(solve(n)? "YES" : "NO");
    }

    return 0;
}

/*

^^^TEST^^^
3
abccaa
abbcca
abcda
-----
YES
NO
YES
$$$TEST$$$

*/
