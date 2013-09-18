class Solution {
public:
    int numbers[12];
    string getPermutation(int n, int k) {
        for (int i = 0; i < n ; i++) {
            numbers[i] = i + 1;
        }
        
        while (--k) {
            next_perm(n);
        }
        string res;
        for (int i = 0; i < n; i++) {
            res += '0' + numbers[i];
        }
        return res;
    }
    
    void next_perm(int n){
        bool done = false;
        for (int i = n - 2; i >= 0; i--) {
            int ii = i + 1;
            if (numbers[i] < numbers[ii]) {
                bool done = false;
                for (int j = n - 1; j > i; j--) {
                    if (numbers[j] >= numbers[i]) {
                        swap(numbers[j], numbers[i]);
                        reverse(numbers + i + 1, numbers + n);
                        done = true;
                        return;
                    }
                }

            }
        }
        if (not done) {
            reverse(numbers, numbers + n);
        }
    }
};
