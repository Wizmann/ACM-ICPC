const long long INF = 1e10;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        // 前缀和
        for (int i = 1; i < n; ++i) {
            skill[i] += skill[i - 1];
        }

        long long st = 0;

        for (int i = 1; i < m; ++i) {
            long long maxTime = st;

            for (int j = 0; j < n; ++j) {
                long long t = 0;

                long long delta = (j - 1 < 0) ? 0 : 1LL * skill[j - 1] * mana[i];
                t = max(t, st + 1LL * skill[j] * mana[i - 1] - delta);

                if (j + 1 < n) {
                    t = max(t, st + 1LL * skill[j + 1] * mana[i - 1] - 1LL * skill[j] * mana[i]);
                }

                maxTime = max(maxTime, t);
            }

            st = maxTime;
        }

        return st + 1LL * skill.back() * mana.back();
    }
};
