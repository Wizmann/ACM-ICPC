class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return findKthElement(nums.begin(), nums.end(), n - k + 1);
    }
private:
    int findKthElement(
            vector<int>::iterator st,
            vector<int>::iterator end,
            int k) {
        int pivot_value = *st;
        auto pivot = partition(st, end, [&pivot_value](int u) {
            return u <= pivot_value;
        });
        iter_swap(st, --pivot);
        
        int dis = distance(st, pivot);
        if (dis + 1 == k) {
            return *pivot;
        } else if (dis + 1 > k) {
            return findKthElement(st, pivot, k);    
        } else {
            return findKthElement(pivot + 1, end, k - dis - 1);
        }
    }
};
