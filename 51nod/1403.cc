#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;

void solve(vector<int>& nums) {
    vector<int> tmp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int u = nums[i];
        int l = i - u - 1;
        int r = i;
        tmp[i] += i - 1;
        tmp[i - 1] -= i - 1;
        tmp[r] += 1;
        tmp[l] -= 1;
    }
    vector<int> ans(n + 1, 0);

    int g = 0;
    for (int i = n; i > 0; i--) {
        g += tmp[i];
        ans[i] = g;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    puts("");
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n);
    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    solve(nums);
    return 0;
}
