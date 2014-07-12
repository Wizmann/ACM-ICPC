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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        auto iter = intervals.begin();
        for (/* pass */; iter != intervals.end(); ++iter) {
            Interval& now = *iter;
            if (now.end < newInterval.start) {
                res.push_back(now);
            } else {
                break;
            }
        }
        for (/* pass */; iter != intervals.end(); ++iter) {
            Interval& now = *iter;
            if (now.start <= newInterval.end) {
                newInterval = merge_interval(now, newInterval);
            } else {
                break;
            }
        }
        res.push_back(newInterval);
        for (/* pass */; iter != intervals.end(); ++iter) {
            Interval& now = *iter;
            res.push_back(now);
        }
        return res;
    }
private:
    Interval merge_interval(const Interval& a, const Interval& b) {
        return Interval(min(a.start, b.start), max(a.end, b.end));
    }
};
