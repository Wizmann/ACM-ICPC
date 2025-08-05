const int MAXI = 7;
const int SIZE = 1 << ((3 * 6) + 2);
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size();
        int fin = encode(vector<int>(n, MAXI));
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;

        for (auto sp: special) {
            for (int i = 0; i < fin; i++) {
                do_solve(i, sp, needs);
            }
        }

        int ans = INF;
        for (int i = 0; i <= fin; i++) {
            ans = min(ans, get_sum(price, needs, i));
        }
        return ans;
    }
private:
    int get_sum(const vector<int>& price, const vector<int>& needs, int cur) {
        int res = 0;
        vector<int> status = decode(cur);
        for (int i = 0; i < n; i++) {
            if (status[i] > needs[i]) {
                return INF;
            }
            res += price[i] * (needs[i] - status[i]);
        }
        return res + dp[cur];
    }

    void do_solve(int cur, const vector<int>& sp, const vector<int>& needs) {
        if (dp[cur] >= INF) {
            return;
        }

        vector<int> status = decode(cur);
        for (int i = 0; i < n; i++) {
            status[i] += sp[i];
            if (status[i] > needs[i]) {
                return;
            }
        }
        int next = encode(status);
        cout << cur << ' ' << next << ' ' << *sp.rbegin() + dp[cur] << endl;
        dp[next] = min(dp[next], dp[cur] + *sp.rbegin());
    }

    int encode(vector<int> status) {
        int res = 0;
        for (auto riter = status.rbegin(); riter != status.rend(); ++riter) {
            res <<= 3;
            res |= *riter;
        }
        return res;
    }
    vector<int> decode(int status) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = status & 7;
            status >>= 3;
        }
        return res;
    }
private:
    int n;
    int dp[SIZE];
};
