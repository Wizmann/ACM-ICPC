#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <functional>
#include <numeric>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MAXI = 111111LL;
const llint INF = 0x3f3f3f3fLL;
const llint MOD = 1000000007LL;

int fib[MAXI];


void init() {
    memset(fib, -1, sizeof(fib));
    llint a = 1;
    llint b = 1;
    while (a < MAXI) {
        fib[b] = a;        
        llint c = a + b;
        a = b;
        b = c;
    }
}

class Solution {
    llint dp[MAXI];
public:
    llint solve(int n, vector<llint>& nums) {
        memset(dp, 0, sizeof(dp));
        
        llint ans = 0;
        llint fibcnt = 0;
        

        for (int i = 0; i <= n; i++) {
            int cur = nums[i];
            if (cur >= 0 && cur < MAXI && fib[cur] != -1) {
                fibcnt++;
                if (cur == 1) {
                    dp[1] += dp[0];
                    dp[0]++;
                } else {
                    int pre = fib[cur];
                    dp[cur] += dp[pre];
                    dp[cur] %= MOD;
                }
            }
        }
        
        for (int i = 0; i < MAXI; i++) {
            ans += dp[i];
            ans %= MOD;
        }
        return ans;
    }
};
    

#define myassert(lhd, rhd) do { \
    if (lhd != rhd) { \
        cout << "L" << __LINE__ << ": assert failed: " << lhd << " != " << rhd << endl; \
        assert(lhd == rhd); \
    } \
} while(0)

void test() {
    init();
    Solution S;
    vector<llint> nums;
    
    nums = {1, 1, 2, INF};
    myassert(S.solve(3, nums), 4);
    
    nums = {1, 1, 2, 2, INF};
    myassert(S.solve(4, nums), 5);
    
    nums = {2, 1, 1, 2, 2, 3, INF};
    myassert(S.solve(6, nums), 7);
}

int main() {
    init();
    
    int n;
    vector<llint> nums;
    
    input(n);
    nums.resize(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
    }
    nums[n] = INF;
    
    Solution* S = new Solution();
    print(S->solve(n, nums));    
    delete S;
    
    return 0;
}
