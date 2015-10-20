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
        min_heap = MinHeap<int>();
        max_heap = MaxHeap<int>();
        vector<int> res;
        
        for (auto num: nums) {
            if (min_heap.empty() && max_heap.empty()) {
                min_heap.push(num);
            } else if (num > max_heap.top()) {
                min_heap.push(num);
            } else {
                max_heap.push(num);
            }
            do_adjust();
            res.push_back(median());
        }
        return res;
    }
private:
    void do_adjust() {
        while (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        while (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    int median() {
        return max_heap.top();
    }
private:
    MinHeap<int> min_heap;
    MaxHeap<int> max_heap;
};

