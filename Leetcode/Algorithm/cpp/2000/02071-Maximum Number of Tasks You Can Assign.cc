class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        
        int l = 0;
        int r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            multiset<int> st;
            for (auto worker : workers) {
                st.insert(worker);
            }
            
            bool flag = true;
            int p = pills;
            for (int i = m - 1; i >= 0; i--) {
                if (st.empty()) {
                    flag = false;
                    break;
                }
                if (*st.rbegin() >= tasks[i]) {
                    st.erase(--st.end());
                    continue;
                }
                if (p) {            
                    auto iter = st.lower_bound(tasks[i] - strength);
                    if (iter != st.end()) {
                        p--;
                        st.erase(iter);
                        continue;
                    }
                }
                    
                flag = false;
                break;
            }
            // cout << m << ' ' << flag << endl;
            if (flag) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        // cout << l << ' ' << r << endl;
        return r;
    }
};
