const int N = 1555;
const int LOGM = 31;

using llint = long long;

int GCD(int a, int b) {
    while (a % b != 0) {
        a = a % b;
        swap(a, b);
    }
    return b;
}

class Solution {
public:
    llint maxGCDScore(vector<int>& nums, int kk) {
        const int n = nums.size();
        llint maxi = 1;
        for (int i = 0; i < LOGM; i++) {
            for (int j = 0; j < n; j++) {
                int gcd = -1;
                int rem = -1;
                for (int k = j; k < n; k++) {
                    int base = 1 << i;
                    if (j == k) {
                        if (nums[k] % base == 0) {
                            gcd = nums[k] / base;
                            rem = 0;
                        } else if (base >= 2 && nums[k] % (base / 2) == 0) {
                            gcd = nums[k] / (base / 2);
                            rem = 1;
                        }
                    } else {
                        if (gcd == -1) {
                            break;
                        }
                        if (nums[k] % base == 0) {
                            gcd = GCD(gcd, nums[k] / base);
                        } else if (base >= 2 && nums[k] % (base / 2) == 0) {
                            gcd = GCD(gcd, nums[k] / (base / 2));
                            rem++;
                        } else {
                            gcd = -1;
                            rem = -1;
                        }
                    }

                    if (gcd != -1 && rem <= kk) {
                        // cout << i << ' ' << j << ' ' << k << ' ' << base << ' ' << gcd << ' ' << rem << ' ' << 1LL * gcd * base * (k - j + 1) << endl;
                        maxi = max(maxi, 1LL * gcd * base * (k - j + 1));
                    }
                }
            }
        }
        return maxi;
    }
};
