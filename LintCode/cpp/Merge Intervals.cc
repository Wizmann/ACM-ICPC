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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        
        sort(
            intervals.begin(),
            intervals.end(),
            [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            }
        );
        
        vector<Interval> res;
        
        Interval cur(*intervals.begin());
        
        for (auto item: intervals) {
            if (item.start > cur.end) {
                res.push_back(cur);
                cur = item;
            } else {
                cur.end = max(cur.end, item.end);
            }
        }
        res.push_back(cur);
        return res;
    }
};
