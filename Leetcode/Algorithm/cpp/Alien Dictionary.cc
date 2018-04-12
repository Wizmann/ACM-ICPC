const int N = 26;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<char> charset;
        
        dis = vector<int>(N, -INF);
        
        for (const auto& word: words) {
            for (const auto c: word) {
                charset.insert(c);
                dis[c - 'a'] = 0;
            }
        }
        
        g.resize(N);
        indegree.resize(N, 0);
        
        int n = words.size();
        for (int i = 0; i + 1 < n; i++) {
            const auto& w1 = words[i];
            const auto& w2 = words[i + 1];
            int m = min(w1.size(), w2.size());
            for (int j = 0; j < m; j++) {
                if (w1[j] == w2[j]) {
                    continue;
                }
                int a = w1[j] - 'a';
                int b = w2[j] - 'a';
                
                if (g[a].count(b) == 0) {
                    g[a].insert(b);
                    indegree[b]++;
                }
                break;
            }
        }
        
        for (auto c: charset) {
            int i = c - 'a';
            if (indegree[i] != 0 || dis[i] != 0) {
                continue;
            }
            queue<int> q;
            q.push(i);
            int step = 1;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                dis[cur] = step++;
                
                for (auto next: g[cur]) {
                    indegree[next]--;
                    if (indegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }
        
        for (auto c: charset) {
            int i = c - 'a';
            if (indegree[i] != 0) {
                cout << c << ' ' << indegree[i] << endl;
                return "";
            }
        }
        
        vector<pair<int, char> > alphabet;
        for (int i = 0; i < N; i++) {
            if (dis[i] != -INF) {
                alphabet.push_back({dis[i], 'a' + i});
            }
        }

        sort(alphabet.begin(), alphabet.end());
        string res;
        for (auto& p: alphabet) {
            res += p.second;
        }

        return res;
    }
private:
    vector<int> indegree;
    vector<int> dis;
    vector<set<int> > g;
};
