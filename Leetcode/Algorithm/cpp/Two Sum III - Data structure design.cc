class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        cout << "add: " << number << endl;
        
        mp[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        cout << "find: " << value << endl;
        if (mp.empty()) {
            return false;
        }
        
        auto l = mp.begin();
        auto r = --mp.end();
        
        while (l != r) {
            if (l->first + r->first > value) {
                r--;
            } else if (l->first + r->first < value) {
                l++;
            } else {
                cout << l->first << ' ' << r->first << endl;
                return true;
            }
        }
        // cout << mp[value / 2] << endl;
        if (value % 2 == 0 && mp.count(value / 2) > 0 && mp[value / 2] >= 2) {
            return true;
        }
        
        return false;
    }
private:
    map<int, int> mp;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
