const int N = 111;
const int INF = 0x3f3f3f3f;

int dp[2][N];
int dis[N][N];

class Solution {
public:
    int minDistance(vector<int>& houses_, int k) {
        houses = houses_;
        sort(houses.begin(), houses.end());
        psum = houses;
        memset(dp, INF, sizeof(dp));
        memset(dis, INF, sizeof(dis));
        int n = houses.size();
        for (int i = 1; i < n; i++) {
            psum[i] += psum[i - 1];
        }
        dp[0][0] = 0;
        int p = 0;
        for (int i = 0; i < k; i++) {
            int q = p ^ 1;
            memset(dp[q], INF, sizeof(dp[q]));
            for (int a = 1; a <= n; a++) {
                if (dp[p][a - 1] >= INF) {
                    continue;
                }
                for (int b = a; b <= n; b++) {
                    int d = get_dis(a, b);
                    dp[q][b] = min(dp[q][b], dp[p][a - 1] + d);
                }
            }
            /*
            for (int j = 0; j <= n; j++) {
                printf("%d ", dp[q][j]);
            }
            puts("");
            */
            p = q;
        }
        return dp[p][n];
    }
    
    int get_dis(int l, int r) {
        if (dis[l][r] < INF) {
            return dis[l][r];
        }
        int ll = l - 1;
        int rr = r - 1;
        int m = rr - ll + 1;
        if (m == 1) {
            return 0;
        }
        m /= 2;
        int mid = ll + m;
        int res = 0;
        res += (mid - ll) * houses[mid] - presum(ll, mid - 1);
        // cout << (mid - ll) * houses[mid] << ' ' << presum(ll, mid - 1) << endl;
        res += presum(mid + 1, rr) - (rr - mid) * houses[mid];
        // cout << presum(mid + 1, rr) << ' ' << (rr - mid) * houses[mid] << endl;
        // printf("%d %d %d %d\n", l, r, mid, res);
        return dis[l][r] = res;
    }
    
    int presum(int l, int r) {
        int vl = l - 1 >= 0? psum[l - 1]: 0;
        int vr = psum[r];
        return vr - vl;
    }
private:
    vector<int> houses;
    vector<int> psum;
};
