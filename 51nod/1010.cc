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

vector<llint> nums;

void init() {
    nums.push_back(1);
    vector<pair<int, int> > ptrs = {
        {2, 0}, {3, 0}, {5, 0}
    };
    
    const llint MAXI = 1123456789012345678;
    while (*nums.rbegin() < MAXI) {
        llint mini = numeric_limits<llint>::max();
        int idx = -1;
        for (int i = 0; i < 3; i++) {
            int value   = ptrs[i].first;
            int num_idx = ptrs[i].second;
            
            llint u = nums[num_idx] * value;
            if (u < mini) {
                mini = u;
                idx = i;
            }
        }
        if (mini != *nums.rbegin()) {
            nums.push_back(mini);
        }
        ptrs[idx].second++;
    }
}

int main() {
    int T;
    llint n;
    input(T);
    
    init();
    
    while (T--) {
        input(n);
        print(*lower_bound(nums.begin() + 1, nums.end(), n));
    }
    return 0;
}
