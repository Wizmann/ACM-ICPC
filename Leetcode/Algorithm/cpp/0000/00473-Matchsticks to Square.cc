const int N = 16;
typedef long long llint;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s <= 0 || s % 4 != 0) {
            return false;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int len = s / 4;
        visit = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                if (!dfs(i + 1, len - nums[i], nums)) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool dfs(int cur, int remains, const vector<int>& nums) {
        if (remains < 0) {
            return false;
        }
        if (remains == 0) {
            return true;
        }
        int n = nums.size();
        for (int i = cur; i < n; i++) {
            if (visit[i]) {
                continue;
            }
            visit[i] = true;
            if (dfs(cur + 1, remains - nums[i], nums)) {
                return true;
            }
            visit[i] = false;
        }
        return false;
    }
private:
    vector<bool> visit;
};
