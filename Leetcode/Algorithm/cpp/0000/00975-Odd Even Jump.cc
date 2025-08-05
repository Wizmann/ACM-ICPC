class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        n = A.size();
        me = vector<int>(n, -1);
        mo = vector<int>(n, -1);
        
        map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            if (mp.empty()) {
                me[i] = mo[i] = -1;
            } else {
                auto iter = mp.lower_bound(A[i]);
                if (iter == mp.end()) {
                    --iter;
                    me[i] = iter->second;
                } else if (iter->first == A[i]) {
                    me[i] = mo[i] = iter->second;
                } else if (iter == mp.begin()){
                    mo[i] = iter->second;
                } else {
                    mo[i] = iter->second;
                    --iter;
                    me[i] = iter->second;
                }
            }
            mp[A[i]] = i;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += dfs(i, 0);
        }
        return res;
    }
private:
    int dfs(int cur, int oe) {
        if (cur == -1) {
            return false;
        }
        if (cur == n - 1) {
            return true;
        }
        if (dp.find({cur, oe}) != dp.end()) {
            return dp[{cur, oe}];
        }
        bool res = false;
        if (oe == 0) {
            // cout << cur << ' ' << oe << ' ' << mo[cur] << endl;
            res |= dfs(mo[cur], oe ^ 1);
        } else {
            // cout << cur << ' ' << oe << ' ' << me[cur] << endl;
            res |= dfs(me[cur], oe ^ 1);
        }
        return dp[{cur, oe}] = res;
    }
private:
    int n;
    map<pair<int, int>, bool> dp;
    vector<int> me, mo;
};
