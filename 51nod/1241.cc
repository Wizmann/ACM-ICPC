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
vector<int> nums;

int main() {
    freopen("input.txt", "r", stdin);
    int x;
    input(n);
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        input(x);
        x--;
        nums[x] = i;
    }

    int pre = numeric_limits<int>::max();
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > pre) {
            cnt++;
            ans = max(ans, cnt);
        } else {
            cnt = 1;
        }
        pre = nums[i];
    }
    print(n - ans);
    return 0;
}
