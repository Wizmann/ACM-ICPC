class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        int n = nums.size();
        return my_kth_element(nums.begin(), nums.end(), n - k + 1);
    }
private:
    int my_kth_element(
            vector<int>::iterator st,
            vector<int>::iterator end,
            int k) {
        auto pivot = my_partition(st, end);
        
        int u = distance(st, pivot);
        
        if (u == k - 1) {
            return *pivot;
        } else if (u < k - 1) {
            return my_kth_element(pivot + 1, end, k - u - 1);
        } else {
            return my_kth_element(st, pivot, k);
        }
    }
    
    vector<int>::iterator my_partition(
            vector<int>::iterator st,
            vector<int>::iterator end) {
        int u = distance(st, end);
        int pivot_nr = rand() % u;
        auto pivot = st + pivot_nr;
        int pivot_value = *pivot;
        iter_swap(st, pivot);
        
        auto l = st;
        auto r = --end;
        while (distance(l, r) >= 0) {
            while (distance(l, r) >= 0 && *l <= pivot_value) {
                l++;
            }
            while (distance(l, r) >= 0 && *r > pivot_value) {
                r--;
            }
            if (distance(l, r) >= 0) {
                iter_swap(l, r);
                l++;
                r--;
            }
        }
        iter_swap(st, r);
        return r;
    } 
};
