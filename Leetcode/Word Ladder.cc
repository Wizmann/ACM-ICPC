const int INF = 1 << 29;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        q.push(start);
        map<string, int> step;
        dict.insert(end);

        while (!q.empty()) {
            string now = q.front();
            q.pop();
            int s = step[now];
            for (auto iter = dict.begin(); iter != dict.end(); /* pass */) {
                if (can_trans(now, *iter)) {
                    step[*iter] = s + 1;
                    q.push(*iter);
                    iter = dict.erase(iter);
                } else {
                    ++iter;
                }
            }
        }
        int ans = step[end];
        if (ans) return ans + 1;
        else return 0;
    }
    
    bool can_trans(const string& a, const string& b) {
        int sz = a.size();
        int cnt = 0;
        for (int i = 0; i < sz; i++) {
            if (a[i] != b[i]) {
                cnt++;
            }
            if (cnt > 1) {
                return false;
            }
        }
        return cnt == 1;
    }
};
