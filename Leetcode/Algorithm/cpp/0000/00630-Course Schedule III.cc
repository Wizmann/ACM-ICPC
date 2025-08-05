class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& va, const vector<int>& vb) {
            return va[1] < vb[1];
        });
        
        multiset<int> st;
        int cur = 0;
        for (auto course: courses) {
            int t = course[0];
            int d = course[1];
            
            st.insert(t);
            cur += t;
            
            if (cur > d) {
                cur -= *st.rbegin();
                st.erase(st.find(*st.rbegin()));
            }
        }
        return st.size();
    }
};
