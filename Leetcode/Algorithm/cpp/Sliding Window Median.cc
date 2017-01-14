class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> res;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (heap_l.empty() && heap_r.empty()) {
                heap_l.insert(num);
            } else if (num > *heap_l.rbegin()) {
                heap_r.insert(num);
            } else {
                heap_l.insert(num);
            }
            
            if (i >= k) {
                int todel = nums[i - k];
                if (heap_l.count(todel) != 0) {
                    heap_l.erase(heap_l.find(todel));
                } else if (heap_r.count(todel) != 0) {
                    heap_r.erase(heap_r.find(todel));
                }
            }
            
            adjust();
            if (i >= k - 1) {
                res.push_back(find_median(k));
            }
        }
        return res;
    }
private:
    void adjust() {
        while (heap_l.size() > heap_r.size() + 1) {
            int num = *heap_l.rbegin();
            heap_r.insert(num);
            heap_l.erase(heap_l.find(num));
        }
        
        while (heap_l.size() < heap_r.size()) {
            int num = *heap_r.begin();
            heap_l.insert(num);
            heap_r.erase(heap_r.find(num));
        }
    }
    
    double find_median(int k) {
        if ((heap_l.size() + heap_r.size()) % 2 == 1) {
            return *heap_l.rbegin();
        }
        double a = *heap_l.rbegin();
        double b = *heap_r.begin();
        return 0.5 * (a + b);
    }
private:
    multiset<int> heap_l;
    multiset<int> heap_r;
};
