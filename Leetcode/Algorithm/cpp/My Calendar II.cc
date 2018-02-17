class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int cur = 0;
        int res = 0;
        if (mp.count(start) == 0) {
            mp[start] = 0;
        }
        if (mp.count(end) == 0) {
            mp[end] = 0;
        }
        for (const auto& p: mp) {
            cur += p.second;
            if (start <= p.first && end > p.first) {
                res = max(res, cur);
            }
        }
        if (res <= 1) {
            mp[start]++;
            mp[end]--;
            return true;
        }
        return false;
    }
private:
    map<int, int> mp;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
