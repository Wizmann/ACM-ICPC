const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned_, int k) {
        for (int i = 0, j = 0; i < n; i++) {
            if (j >= banned_.size() || i != banned_[j]) {
                banned.insert(i);
            } else {
                j++;
            }
        }

        queue<int> q;
        q.push(p);
        vector<int> dis(n, INF);
        dis[p] = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            int l1 = max(0, cur - k + 1);
            int r1 = l1 + k - 1;
            int nxt1 = r1 - (cur - l1);

            int l2 = min(cur, n - k);
            int r2 = l2 + k - 1;
            int nxt2 = r2 - (cur - l2);

            int step = dis[cur] + 1;

            auto iter = banned.lower_bound(nxt1);
            while (iter != banned.end() && *iter <= nxt2) {
                if (*iter % 2 != nxt1 % 2) {
                    ++iter;
                    continue;
                }

                if (dis[*iter] > step) {
                    dis[*iter] = step;
                    q.push(*iter);
                    iter = banned.erase(iter);
                } else {
                    ++iter;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dis[i] >= INF) {
                dis[i] = -1;
            }
        }
        return dis;
    }
private:
    set<int> banned;
};
