#include <bitset>

const int SIZE = 32;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, int> dis;
        dict.insert(end);
        for (const auto& str: dict) {
            dis[str] = INF;
        }
        dis[start] = 0;

        queue<string> q;
        q.push(start);
        
        while (!q.empty()) {
            const auto& cur = q.front();
            q.pop();
            int step = dis[cur];
            
            for (auto iter = dict.begin(); iter != dict.end(); /* pass */) {
                const auto& str = *iter;
                if (!trans(cur, str)) {
                    ++iter;
                    continue;
                }
                dis[str] = step + 1;
                q.push(str);
                iter = dict.erase(iter);
            }
        }
        return dis[end] == INF? 0: dis[end] + 1;
    }
private:
    bool trans(const string& a, const string& b) {
        int n = a.size();
        int diff = 0;
        for (int i = 0; i < n && diff < 2; i++) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
        return diff <= 1;
    }
};
