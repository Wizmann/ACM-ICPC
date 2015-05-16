class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        queue<int> q;
        int ans = 0;
        
        for (auto c: s) {
            if (st.find(c) == st.end()) {
                st.insert(c);
                q.push(c);
                ans = max(ans, static_cast<int>(q.size()));
                continue;
            }
            while (st.find(c) != st.end()) {
                char cc = q.front();
                q.pop();
                st.erase(cc);
            }
            st.insert(c);
            q.push(c);
        }
        return ans;
    }
};
