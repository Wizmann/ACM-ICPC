class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        int g = gcd(k, n);
        for (int i = 0; i < g; i++) {
            int p = i;
            int u = nums[p];
            
            do {
                int q = (p + k) % n;
                swap(nums[q], u);
                p = q;
            } while (p != i);
        }
    }
private:
    int gcd(int a, int b) {
        if (a < b) {
            return gcd(b, a);
        }
        if (b == 0) {
            return -1;
        }
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }
};

//

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        if (k == 0) {
            return;
        }
        k = n - k;
        
        reverse(nums, nums + k);
        reverse(nums + k, nums + n);
        reverse(nums, nums + n);
    }
};
