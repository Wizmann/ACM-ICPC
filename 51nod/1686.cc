#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111111;

typedef long long llint;

map<int, int> mp, rmp;
vector<int> g[SIZE];
vector<int> nums;

int n, k;

llint check(int v) {
    int maxi = -1;
    llint res = 0;
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        int idx = distance(g[x].begin(), lower_bound(g[x].begin(), g[x].end(), i));
        if (idx + 1 >= v) {
            idx -= v - 1;
            maxi = max(maxi, g[x][idx]);
        }
        res += maxi + 1;
    }
    return res;
}

int main() {
    input(n >> k);
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        mp[nums[i]] = -1;
    }
    
    int idx = 0;
    for (auto& p: mp) {
        p.second = idx;
        rmp[idx] = p.first;
        idx++;
    }
    
    int max_cnt = 0;
    for (int i = 0; i < n; i++) {
        nums[i] = mp[nums[i]];
        g[nums[i]].push_back(i);
        max_cnt = max(max_cnt, (int)g[nums[i]].size());
    }
    
    int l = 1;
    int r = max_cnt;
    
    while (l <= r) {
        int m = (l + r) >> 1;
        if (check(m) >= k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    print(r);
    
    return 0;
}
