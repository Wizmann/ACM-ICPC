class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        
        int res = 0;
        int cur = 0;
        for (const auto& p: mp) {
            cur += p.second;
            res = max(res, cur);
        }
        return res;
    }
private:
    map<int, int> mp;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
