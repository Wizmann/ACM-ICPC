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
        for (vector<Interval>::iterator iter = intervals.begin();
                    iter != intervals.end();
                    /*Nope*/) {
            if (intersect(*iter, newInterval)) {
                iter = intervals.erase(iter);
            } else {
                ++iter;
            }
        }

        vector<Interval> res;
        if (intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }
        for (vector<Interval>::iterator iter = intervals.begin();
                    iter != intervals.end();
                    ++iter) {
            if (iter->end < newInterval.start ||
                        iter->start > newInterval.end) {
                res.push_back(*iter);
            } else {
                res.push_back(newInterval);
            }
        }
        return res;
    }

    bool intersect(const Interval& now, Interval& next) 
    {
        if ( (next.start - now.start) * (next.end - now.start) < 0 ||
             (next.start - now.end  ) * (next.end - now.end  ) < 0 ||
             (now.start - next.start) * (now.end - next.start) < 0 ||
             (now.start - next.end  ) * (now.end - next.end  ) < 0 ) {
            next.start = min(next.start, now.start);
            next.end   = min(next.end,   now.end  );
            return true;
        }
        return false;
    }
};