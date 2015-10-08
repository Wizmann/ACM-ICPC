class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = distance(nums.begin(), my_lower_bound(nums.begin(), nums.end(), target));
        int b = distance(nums.begin(),   my_upper_bound(nums.begin(), nums.end(), target));
        int n = nums.size();
        
        if (a >= n || nums[a] != target || b - 1 >= n || nums[b - 1] != target) {
            return {-1, -1};
        }
        
        return {a, b - 1};
    }
private:
    vector<int>::iterator my_lower_bound(vector<int>::iterator begin, vector<int>::iterator end, int target) {
        --end;
        while (begin <= end) {
            auto mid = begin + distance(begin, end) / 2;
            if (*mid >= target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return begin;
    }
    
    vector<int>::iterator my_upper_bound(vector<int>::iterator begin, vector<int>::iterator end, int target) {
        --end;
        while (begin <= end) {
            auto mid = begin + distance(begin, end) / 2;
            if (*mid > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return begin;
    }
};
