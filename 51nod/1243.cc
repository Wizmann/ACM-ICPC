#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int MAXI = 0x3f3f3f3f;
int n, x, m;
vector<int> stubs;

bool solve(int mid) {
    int pre = 0;
    for (auto stub: stubs) {
        int cur = pre + 2 * x;
        cur = max(stub - mid + x, cur);
        if (cur - x - stub > mid) {
            return false;
        }
        pre = cur;
    }
    return pre < m;
}

int main() {
    freopen("input.txt", "r", stdin);
    int a;
    input(n >> x >> m);
    for (int i = 0; i < n; i++) {
        input(a);
        stubs.push_back(a);
    }
    sort(stubs.begin(), stubs.end());
    
    if (n * x * 2 > m) {
        print(-1);
        exit(0);
    }
    
    int l = 0;
    int r = MAXI;
    
    while (l <= r) {
        int mid = static_cast<llint>(l + r) >> 1;
        if (solve(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    print(l);
    return 0;
}
