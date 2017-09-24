const int SIZE = 1234;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        k++;
        int n = tasks.size();
        int ans = 0;
        unordered_map<char, int> counter;
        for (auto task: tasks) {
            counter[task]++;
        }
        for (const auto& p: counter) {
            g[p.second].push_back(p.first);
        }
        
        // string s = "";
        
        while (n) {
            int cnt = 0;
            unordered_set<char> st;
            for (int i = SIZE - 1; cnt < k && i > 0; i--) {
                for (auto iter = g[i].begin(); cnt < k && iter != g[i].end(); /* pass */) {
                    if (st.find(*iter) != st.end()) {
                        ++iter;
                        continue;
                    }
                    
                    cnt++;
                    n--;
                    
                    // s += *iter;
                    
                    st.insert(*iter);
                    g[i - 1].push_back(*iter);
                    iter = g[i].erase(iter);
                }
            }
            if (n == 0) {
                ans += cnt;
            } else {
                /*
                while (cnt < k) {
                    s += "_";
                    cnt++;
                }
                */
                ans += k;
            }
        }
        // cout << s << endl;
        return ans;
    }
private:
    vector<char> g[SIZE];
};
