const int INF = 1 << 25;

struct cmp {
    Interval it;
    cmp(const Interval& i_it)
    {
        it = i_it;
    }
    bool operator ()(const Interval& a, const Interval& b)
    {
        return a.start < b.start;
    }
};

 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        vector<Interval> res;
        if (!intervals.size()) {
            return res;
        } else {
            intervals.push_back(Interval(INF, INF));
        }
        sort(intervals.begin(), intervals.end(), cmp(intervals[0]));
        int st  = intervals[0].start;
        int end = intervals[0].end;
        for (int i = 0; i < intervals.size(); i++) {
            if (in_interval(intervals[i], st, end)) {
                end = max(end, intervals[i].end);
            } else {
                res.push_back(Interval(st, end));
                st  = intervals[i].start;
                end = intervals[i].end; 
            }
        }
        return res;
    }

    bool in_interval(const Interval& interval, int st, int end)
    {
        if (1LL * (interval.start - st) * (interval.start - end) <= 0) {
            return true;
        } else {
            return false;
        }
    }
};
