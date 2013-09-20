class Solution {
public:
    int numbers[12];
    string getPermutation(int n, int k) {
        for (int i = 1; i <= n; i++) {
            numbers[i-1] = i;
        }
        
        k--;
        int maxi = 1;
        for (int i = 1; i <= n; i++) {
            maxi *= i;
        }
        k %= maxi;
        
        while (k--) {
            next_perm(n);
        }

        string res;
        for (int i = 0; i < n; i++) {
            res += numbers[i] + '0';
        }
        return res;
    }
    
    void next_perm(int n) {
        for (int i = n - 2; i >= 0; i--) {
            int ii = i + 1;
            if (numbers[i] < numbers[ii]) {
                int p = get_max_pos(n, i);
                swap(numbers[i], numbers[p]);
                reverse(numbers + i + 1, numbers + n);
                break;
            }
        }
    }
    
    int get_max_pos(int n, int p) {
        for (int i = n - 1; i > p; i--) {
            if (numbers[i] >= numbers[p]) return i;
        }
        return -1;
    }
};
