class Solution {
public:
    int reverse(int x) {
        int g = 1;
        if (x < 0) g = -1;
        
        int res = 0;
        
        while (x != 0) {
            int t = abs(x % 10);
            x /= 10;
            
            res = res * 10 + t;
        }
        
        return res * g;
    }
};
