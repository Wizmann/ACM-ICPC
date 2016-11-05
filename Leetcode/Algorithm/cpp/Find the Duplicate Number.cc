// O(n) solution
// fast slow pointer, treat the array as an linked list with a circle in it
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int fast = n;
        int slow = n;
        
        while (true) {
            fast = nums[fast - 1];
            fast = nums[fast - 1];
            slow = nums[slow - 1];
            
            if (fast == slow) {
                break;
            }
        }
        
        fast = n;
        while (true) {
            fast = nums[fast - 1];
            slow = nums[slow - 1];
            
            if (fast == slow) {
                break;
            }
        }
        return slow;
    }
};

// ================

// O(n * logn) solution
// basic binary search

class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = n - 1;
        
        while (l <= r) {
            int m = (1LL * l + r) >> 1;
            int lt = 0;
            int gt = 0;
            int eq = 0;
            
            for (auto num: nums) {
                if (num < l || num > r) {
                    continue;
                }
                if (num < m) {
                    lt++;
                } else if (num == m) {
                    eq++;
                } else {
                    gt++;
                }
            }
            if (eq > 1) {
                return m;
            }
            int lc = m - l;
            int rc = r - m;
            
            if (lt > lc) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};
