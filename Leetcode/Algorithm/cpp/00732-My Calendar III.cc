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


// ---

class MyCalendarThree {
public:
    MyCalendarThree() {
        // pass
    }
    
    int book(int start, int end) {
        // print(">>", start, end);
        auto iter1 = lower_bound(pos.begin(), pos.end(), start);
        iter1 = pos.insert(iter1, start);

        auto iter2 = lower_bound(neg.begin(), neg.end(), end);
        neg.insert(iter2, end);

        auto iter3 = lower_bound(neg.begin(), neg.end(), start);

        int maxi = 0;
        while (iter1 != pos.end() && *iter1 < end) {
            while (iter3 != neg.end() && *iter3 <= *iter1) {
                iter3++;
            }
            int cnt = distance(pos.begin(), iter1) + 1 - distance(neg.begin(), iter3);
            // print(*iter1, cnt);
            maxi = max(maxi, cnt);
            ++iter1;
        }
        // print(maxi);
        res = max(res, maxi);
        return res;
    }
private:
    vector<int> pos;
    vector<int> neg;
    int res = 0;
};
