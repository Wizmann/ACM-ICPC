template <typename T>
class MinHeap: public priority_queue<T, vector<T>, greater<T> > {};

template <typename T>
class MaxHeap: public priority_queue<T, vector<T>, less<T> > {};

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        vector<int> res;
        
        int n = nums.size();
        
        MaxHeap<int> left;
        MinHeap<int> right;
        
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            
            if (left.empty() || num < left.top()) {
                left.push(num);
            } else {
                right.push(num);
            }
            
            while (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }
            
            while (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }
            res.push_back(left.top());
        }
        return res;
    }
};

