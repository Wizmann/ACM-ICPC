class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        sort(num.begin(), num.end());
        int ans = INF;
        for (int i = 0; i < n; i++) {
            int p = i + 1, q = n - 1;
            while (p < q) {
                int s = num[i] + num[p] + num[q];
                int delta = abs(target - s);
                if (abs(target - s) < abs(target - ans)) {
                    ans = s;
                }
                (s > target)? q--: p++;
            }
        }
        return ans;
    }
private:
    const int INF = 0xdeadbeef;
};
