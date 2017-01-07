#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
vector<int> ns;

int dfs(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == r) {
        return 1;
    }
    
    int maxi = numeric_limits<int>::min();
    int ptr = -1;
    
    for (int i = l; i <= r; i++) {
        if (ns[i] > maxi) {
            maxi = ns[i];
            ptr = i;
        }
    }
    return max(dfs(l, ptr - 1), dfs(ptr + 1, r)) + 1;
}

int main() {
    input(n);
    ns.resize(n);
    for (int i = 0; i < n; i++) {
        input(ns[i]);
    }
    print(dfs(0, n - 1));
    return 0;
}
