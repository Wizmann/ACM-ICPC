/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

bool operator < (const Interval& i1, const Interval& i2) {
    return i1.end < i2.start;
}

class Solution1 {
public:
    /**
     * @param seqA: the list of intervals
     * @param seqB: the list of intervals
     * @return: the time periods
     */
    vector<Interval> timeIntersection(vector<Interval> &seqA, vector<Interval> &seqB) {
        set<Interval> st;
        for (const auto& interval: seqA) {
            st.insert(interval);
        }
        
        vector<Interval> result;
        for (const auto& interval: seqB) {
            while (true) {
                auto iter = st.find(interval);
                if (iter == st.end()) {
                    break;
                }
                auto cur = *iter;
                st.erase(iter);
                
                if (cur.start < interval.start) {
                    st.insert({cur.start, interval.start - 1});
                }
                if (cur.end > interval.end) {
                    st.insert({interval.end + 1, cur.end});
                }
                
                result.push_back({max(cur.start, interval.start), min(cur.end, interval.end)});
            }
        }
        return result;
    }
};

class Solution2 {
public:
    /**
     * @param seqA: the list of intervals
     * @param seqB: the list of intervals
     * @return: the time periods
     */
    vector<Interval> timeIntersection(vector<Interval> &seqA, vector<Interval> &seqB) {
        sort(seqA.begin(), seqA.end());
        sort(seqB.begin(), seqB.end());
        
        vector<Interval> result;
        
        const int n = seqA.size();
        const int m = seqB.size();
        
        for (int p = 0, q = 0; p < n && q < m; /* pass */) {
            if (seqA[p] < seqB[q]) {
                p++;
            } else if (seqB[q] < seqA[p]) {
                q++;
            } else {
                result.push_back({max(seqA[p].start, seqB[q].start), min(seqA[p].end, seqB[q].end)});
                if (seqA[p].end > seqB[q].end) {
                    q++;
                } else {
                    p++;
                }
            }
        }
        return result;
    }
};
