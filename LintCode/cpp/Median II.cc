template <typename T>
class MaxHeap: public priority_queue<T, vector<T>, less<T> > {};

template <typename T>
class MinHeap: public priority_queue<T, vector<T>, greater<T> > {};

class Solution {
public:
    vector<int> medianII(vector<int> &nums) {
        MaxHeap<int> max_heap;
        MinHeap<int> min_heap;
        vector<int> res;
        
        for (auto num: nums) {
            if (max_heap.empty() || max_heap.top() > num) {
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }
            
            while (max_heap.size() > min_heap.size() + 1) {
                int u = max_heap.top();
                max_heap.pop();
                min_heap.push(u);
            }
            
            while (max_heap.size() < min_heap.size()) {
                int u = min_heap.top();
                min_heap.pop();
                max_heap.push(u);
            }

            res.push_back(max_heap.top());
        }
        return res;
    }
};

