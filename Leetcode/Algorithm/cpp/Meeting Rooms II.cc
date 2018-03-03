/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        multiset<pair<int, int> > st;
        for (auto interval: intervals) {
            st.insert({interval.start, 1});
            st.insert({interval.end, -1});
        }
        
        int cur = 0;
        int maxi = 0;
        for (auto p: st) {
            cur += p.second;
            maxi = max(maxi, cur);
        }
        return maxi;
    }
};
