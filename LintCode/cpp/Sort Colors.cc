class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ptr = 0;
        
        while (ptr <= r) {
            switch(nums[ptr]) {
                case 0: {
                    swap(nums[ptr], nums[l]);
                    ptr = max(ptr, ++l);
                } break;
                case 1: {
                    ptr++;
                } break;
                case 2: {
                    swap(nums[ptr], nums[r--]);
                } break;
            }
        }
    }
};
