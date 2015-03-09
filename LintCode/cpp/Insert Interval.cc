/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        intervals.push_back({INF, INF});
        for (auto iter = intervals.begin(); iter != intervals.end(); /* pass */) {
            if (overlap(*iter, newInterval)) {
                newInterval = merge_interval(*iter, newInterval);
                iter = intervals.erase(iter);
            } else {
                if (iter->start > newInterval.end) {
                    intervals.insert(iter, newInterval);
                    break;
                }
                ++iter;
            }
        }
        intervals.pop_back();
        return intervals;
    }
private:
    bool overlap(const Interval& a, const Interval& b) {
        return (b.start <= a.start && a.start <= b.end) ||
               (b.start <= a.end   && a.end   <= b.end) ||
               (a.start <= b.start && b.start <= a.end) ||
               (a.start <= b.end   && b.end   <= a.end);
    }
    
    Interval merge_interval(const Interval& a, const Interval& b) {
        int start = min(a.start, b.start);
        int end   = max(a.end,   b.end);
        return Interval(start, end);
    }
private:
    static const int INF = 0x3f3f3f3f;
};
