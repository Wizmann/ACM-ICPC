const int INF = 0x3f3f3f3f;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> step(10000, INF);
        queue<int> q;
        
        step[0] = 0;
        for (auto dd: deadends) {
            step[to_int(dd)] = -1;
        }

        q.push(0);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            int u = step[cur];
            if (u == -1) {
                continue;
            }
            
            auto nexts = get_next(cur);
            for (auto next: nexts) {
                // cout << next << endl;
                if (step[next] > u + 1) {
                    step[next] = u + 1;
                    q.push(next);
                }
            }
        }
        
        int tt = to_int(target);
        cout << step[tt] << endl;
        if (step[tt] == -1 || step[tt] == INF) {
            return -1;
        }
        return step[tt];
    }
private:
    int to_int(const string& s) {
        int res = 0;
        for (auto c: s) {
            res = res * 10 + c - '0';
        }
        return res;
    }
    
    string to_str(int u) {
        string s = "";
        for (int i = 0; i < 4; i++) {
            s = to_string(u % 10) + s;
            u /= 10;
        }
        return s;
    }
    
    vector<int> get_next(int cur) {
        vector<int> nexts;
        
        string s = to_str(cur);
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                string ss = s;
                ss[i] += j == 1? 1: -1;
                
                if (ss[i] < '0') {
                    ss[i] = '9';
                }
                
                if (ss[i] > '9') {
                    ss[i] = '0';
                }
                
                nexts.push_back(to_int(ss));
            }
        }
        return nexts;
    }
};
