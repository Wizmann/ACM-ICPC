class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        m_ans.clear();
        st.clear();
        sort(num.begin(), num.end());
        vector<vector<int> > tmp;
        do_sum(4, num, target, tmp, 0, num.size() - 1);
        
        for (auto iter = m_ans.begin(); iter != m_ans.end(); /* pass */) {
            sort(iter -> begin(), iter -> end());
            if (st.find(*iter) != st.end()) {
                iter = m_ans.erase(iter);
            } else {
                st.insert(*iter);
                ++iter;
            }
        }
        return m_ans;
    }
    
    void do_sum(int n, vector<int>& num, int target, vector<vector<int> >& ans, int l, int r) {
        if (n == 2) {
            two_sum(num, target, ans, l, r);
        } else {
            ans.clear();
            for (int i = l; i < r; i++) {
                int nl = i + 1;
                int nr = r;
                int nt = target - num[i];
                
                vector<vector<int> > tmp;
                do_sum(n - 1, num, nt, tmp, nl, nr);
                
                for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
                    iter -> push_back(num[i]);
                    ans.push_back(*iter);
                }
            }
            if (n == 4) {
                m_ans.insert(m_ans.end(), ans.begin(), ans.end());
            }
        }
    }
    
    void two_sum(vector<int>& num, int target, vector<vector<int> >& ans, int l, int r) {
        while (l < r) {
            while (l < r && num[l] + num[r] > target) r--;
            while (l < r && num[l] + num[r] >= target) {
                if (num[l] + num[r] == target) {
                    vector<int> v;
                    v.push_back(num[l]);
                    v.push_back(num[r]);
                    ans.push_back(v);
                }
                r--;
            }
            l++;
        }
    }
private:
    vector<vector<int> > m_ans;
    set<vector<int> > st;
};
