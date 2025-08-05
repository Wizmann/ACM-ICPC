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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedules) {
        vector<pair<int, int> > intervals;
        
        for (const auto& schedule: schedules) {
            for (const auto& interval: schedule) {
                intervals.push_back({interval.start, interval.end});
            }
        }
        
        sort(intervals.begin(), intervals.end());
        
        vector<Interval> result;
        int p = intervals.begin()->first;
        for (const auto& interval: intervals) {
            if (p < interval.first) {
                result.push_back({p, interval.first});
                p = interval.second;
            } else {
                p = max(p, interval.second);
            }
        }
        return result;
    }
};
