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
    vector<Interval> merge(vector<Interval>& intervals) {
        intervals.push_back({INF, INF});
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
    
        vector<Interval> res;
        int head = intervals[0].start;
        int tail = intervals[0].end;
        
        for (auto interval: intervals) {
            if (interval.start > tail) {
                res.push_back({head, tail});
                head = interval.start;
                tail = interval.end;
            } else {
                tail = max(tail, interval.end);
            }
        }
        return res;
    }
};
