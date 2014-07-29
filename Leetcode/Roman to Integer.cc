class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int ptr = 0;
        while (ptr < s.size() && s[ptr] == 'M') {
            ans += 1000;
            ptr++;
        }
        ans += do_sum10('C', 'M', ptr, s) * 100;
        ans += do_sum5('C', 'D', ptr, s) * 100;
        
        ans += do_sum10('X', 'C', ptr, s) * 10;
        ans += do_sum5('X', 'L', ptr, s) * 10;
        
        ans += do_sum10('I', 'X', ptr, s) * 1;
        ans += do_sum5('I', 'V', ptr, s) * 1;
        return ans;
    }
private:
    int do_sum10(int I, int X, int& ptr, const string& s) {
        int res = 0;
        int _ptr = ptr;
        bool flag = false;
        while (ptr < s.size() && s[ptr] == I) {
            res -= 1;
            ptr++;
        }
        
        while (ptr < s.size() && s[ptr] == X) {
            flag = true;
            res += 10;
            ptr++;
        }
        if (!flag) {
            ptr = _ptr;
            res = 0;
        }
        return res;
    }

    int do_sum5(int I, int V, int& ptr, const string& s) {
        int res = 0;
        while (ptr < s.size() && s[ptr] == I) {
            res += 1;
            ptr++;
        }
        while (ptr < s.size() && s[ptr] == V) {
            res *= -1;
            res += 5;
            ptr++;
        }
        while (ptr < s.size() && s[ptr] == I) {
            res += 1;
            ptr++;
        }
        return res;
    }
};
