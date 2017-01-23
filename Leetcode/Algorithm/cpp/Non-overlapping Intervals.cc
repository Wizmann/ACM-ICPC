/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& ia, const Interval& ib) {
            return ia.start < ib.start;
        });
        
        int ans = 0;
        int n = intervals.size();
        int p = -INF;
        
        for (int i = 0; i < n; i++) {
            int l = intervals[i].start;
            int r = intervals[i].end;
            
            if (l >= p) {
                ans++;
                p = r;
            } else {
                p = min(r, p);
            }
        }
        return n - ans;
    }
};
