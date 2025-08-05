typedef long long llint;

const int INF = 0x3f3f3f3f;

struct NumPair {
    int a, b;
};

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size();
        vector<NumPair> ps;
        for (int i = 0; i < n; i++) {
            ps.push_back({nums1[i], nums2[i]});
        }
        sort(ps.begin(), ps.end(),
             [](const NumPair& p1, const NumPair& p2) {
                 return p1.b > p2.b;
             });

        priority_queue<int, vector<int>, greater<int> > pq;
        int mini = INF;
        llint tot = 0;
        llint ans = 0;
        for (const auto& p : ps) {
            mini = min(mini, p.b);
            pq.push(p.a);
            tot += p.a;
            if (pq.size() > k) {
                tot -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = max(ans, 1LL * mini * tot);
            }
        }
        return ans;
    }
};
