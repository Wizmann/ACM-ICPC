typedef long long llint;


const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3fLL;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        const int n = nums.size();

        vector<llint> cost(n, INFLL);

        multiset<int> left, right;
        llint left_sum = 0;
        llint right_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i - x >= 0) {
                int pre = nums[i - x];
                if (left.count(pre)) {
                    left.erase(left.find(pre));
                    left_sum -= pre;
                } else if (right.count(pre)) {
                    right.erase(right.find(pre));   
                    right_sum -= pre;
                } else {
                    assert(false);
                }
            }
            int cur = nums[i];
            left.insert(cur);
            left_sum += cur;

            while (left.size() > (x + 1) / 2) {
                int cur = *left.rbegin();
                right.insert(cur);
                right_sum += cur;
                left_sum -= cur;
                left.erase(left.find(cur));
            }

            while (!left.empty() && !right.empty() && *left.rbegin() > *right.begin()) {
                int a = *left.rbegin();
                int b = *right.begin();
                left_sum = left_sum - a + b;
                right_sum = right_sum - b + a;
                left.erase(left.find(a));
                left.insert(b);
                right.erase(right.find(b));
                right.insert(a);
            }
            if (left.size() + right.size() == x) {
                llint mid = *left.rbegin();
                cost[i] = 1LL * left.size() * mid - left_sum + right_sum - mid * right.size();
            }
        }

        /*
        for (int i = 0; i < n; i++) {
            cout << cost[i] << ' ';
        }
        cout << endl;
        */

        vector<vector<llint>> dp(k + 1);
        dp[0] = vector<llint>(n, 0);
        for (int i = 1; i <= k; i++) {
            dp[i] = vector<llint>(n, INFLL);
        }

        for (int i = x - 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                llint pre = INFLL;
                if (j == 1 && i - x < 0) {
                    pre = 0;
                } else if (i - x >= 0) {
                    pre = dp[j - 1][i - x];
                }
                dp[j][i] = pre + cost[i];
                dp[j][i] = min(dp[j][i], dp[j][i - 1]);
                // cout << i << ' ' << j << ' ' <<  dp[j][i] << endl;
            }
        }

        llint mini = INFLL;
        for (int i = x - 1; i < n; i++) {
            mini = min(mini, dp[k][i]);
        }
        return mini;

    }
};
