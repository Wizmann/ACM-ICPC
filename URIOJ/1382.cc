// Result: 1382	Wizmann	Accepted	C++	0.036
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int solve(vector<int>& nums) {
    int n = nums.size();
    vector<bool> visit(n, false);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (visit[i]) {
            continue;
        }
        int ptr = i;
        int cnt = 0;

        while (!visit[ptr]) {
            visit[ptr] = true;
            cnt++;
            ptr = nums[ptr];
        }

        ans += cnt - 1;
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);

    while (T--) {
        int n;
        vector<int> nums;

        input(n);
        nums.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
            nums[i]--;
        }
        print(solve(nums));
    }
    return 0;
}
