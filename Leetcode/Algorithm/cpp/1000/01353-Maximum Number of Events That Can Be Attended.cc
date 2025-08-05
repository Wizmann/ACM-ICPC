# https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        multiset<int> st;
        int cur = -1;
        int n = events.size();
        sort(events.begin(), events.end());
        int ptr = 0;
        int tot = 0;
        while (ptr < n || !st.empty()) {
            while (ptr < n && events[ptr][0] <= cur) {
                st.insert(events[ptr][1]);
                ptr++;
            }
            while (!st.empty() && *st.begin() < cur) {
                st.erase(st.begin());
            }
            if (!st.empty()) {
                tot += 1;
                cur += 1;
                st.erase(st.begin());
            } else if (ptr < n) {
                cur = events[ptr][0];
            }
        }
        return tot;
    }
};
