#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;

llint inversion(int nums[], int l, int r) {
    if (r == l + 1) {
        return 0;
    }
    llint ans = 0;
    int n = r - l;

    int m = l + n / 2;

    ans += inversion(nums, l, m);
    ans += inversion(nums, m, r);

    vector<int> tmp;
    tmp.reserve(n);

    int pl = l;
    int pr = m;

    while (pl < m && pr < r) {
        if (nums[pl] <= nums[pr]) {
            tmp.push_back(nums[pl]);
            pl++;
        } else {
            ans += m - pl;
            tmp.push_back(nums[pr]);
            pr++;
        }
    }

    while (pl < m) {
        tmp.push_back(nums[pl]);
        pl++;
    }

    while (pr < r) {
        tmp.push_back(nums[pr]);
        pr++;
    }

    assert(tmp.size() == n);
    for (int i = 0; i < n; i++) {
        nums[l + i] = tmp[i];
    }
    
    return ans;
}

int A[SIZE];

int main() {
    int n, m;
    while (input(n >> m)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        llint res = max(0LL, inversion(A, 0, n) - m);
        printf("%lld\n", res);
    }

    return 0;
}
