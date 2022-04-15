typedef long long llint;

const int MOD = 1'000'000'000 + 7;
const int N = 1234567 + 123456;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        vector<int> ns(N, 0);
        for (auto num : nums) {
            ns[num]++;
        }
        int cur = 0;
        while (k) {
            while (cur < N && ns[cur] == 0) {
                cur++;
            }
            ns[cur + 1]++;
            ns[cur]--;
            k--;
        }
        
        llint res = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < ns[i]; j++) {
                res = (res * i) % MOD;
            }
        }
        
        return res;
    }
};
