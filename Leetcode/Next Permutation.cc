class Solution {
public:
    static const int INF = 1 << 29;
    void nextPermutation(vector<int> &num) {
        if (num.size() == 0) return;
        
        int n = num.size();
        
        bool done = false;
        for (int i = n - 2; i >= 0; i--) {
            int ii = i + 1;
            if (num[i] < num[ii]) {
                int p = find_greater(num, i);
                swap(num[i], num[p]);
                reverse(num.begin() + ii, num.end());
                done = true;
                break;
            }
        }
        
        if (not done) {
            reverse(num.begin(), num.end());
        }
    }
    
    int find_greater(vector<int> &num, int x) {
        for (int i = num.size() - 1; i > x; i--) {
            if (num[i] > num[x]) return i;
        }
    }
};
