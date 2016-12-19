/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        mp.clear();
    }
    
    void addNum(int val) {
        if (mp.empty()) {
            mp[val] = val;
            return;
        }
        
        if (contains(val)) {
            return;
        }
        
        int l = val;
        int r = val;
        
        auto iter0 = mp.upper_bound(val);
        if (iter0 != mp.end()) {
            if (iter0->first == val + 1) {
                r = iter0->second;
                mp.erase(iter0);
            } else {
                // pass
            }
        }
        
        auto iter1 = mp.upper_bound(val);
        if (iter1 != mp.begin()) {
            --iter1;
            if (iter1->second == val - 1) {
                l = iter1->first;
                mp.erase(iter1);
            } else {
                // pass
            }
        }
        
        mp.insert({l, r});
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> intervals;
        for (auto p: mp) {
            intervals.push_back({p.first, p.second});
        }
        return intervals;
    }
    
    bool contains(int val) {
        auto iter0 = mp.upper_bound(val);
        auto iter1 = iter0;
        
        if (iter0 != mp.begin()) {
            --iter0;
        }
        
        return _contains(iter0, val) || _contains(iter1, val);
    }
private:
    bool _contains(map<int, int>::iterator iter, int val) {
        if (iter != mp.end()) {
            int a = iter->first;
            int b = iter->second;
            if (a <= val && val <= b) {
                return true;
            }
        }
        return false;
    }
private:
    map<int, int> mp;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
