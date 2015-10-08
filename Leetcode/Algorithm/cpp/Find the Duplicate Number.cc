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
