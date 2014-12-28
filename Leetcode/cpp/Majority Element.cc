class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num.size();
        return kth_element(num, (n + 1) / 2);
    }
private:
    int kth_element(vector<int>& num, int k) {
        int n = num.size();
        return kth_element(num, 0, n, k);
    }
    
    int kth_element(vector<int>& num, int st, int end, int k) {
        int pivot_idx = partition(num, st, end);
        if (pivot_idx - st + 1 == k) {
            return num[pivot_idx];
        }
        if (pivot_idx - st >= k) {
            return kth_element(num, st, pivot_idx, k);
        } else {
            return kth_element(num, pivot_idx + 1, end, k - (pivot_idx - st) - 1);
        }
    }
    
    int partition(vector<int>& num, int st, int end) {
        int pivot_idx = (rand() % (end - st)) + st;
        int pivot = num[pivot_idx];
        swap(num[pivot_idx], num[st]);
        
        int l = st, r = end - 1;
        int flag = 0;
        
        while (l <= r) {
            while (l <= r && num[l] <= pivot) {
                if (num[l] < pivot) {
                    // pass
                } else if (flag == 0) {
                    flag ^= 1;
                } else {
                    break;
                }
                l++;
            }
            while (l <= r && num[r] >= pivot) {
                if (num[r] > pivot) {
                    // pass
                } else if (flag == 1) {
                    flag ^= 1;
                } else {
                    break;
                }
                r--;
            }
            if (l <= r) {
                swap(num[l++], num[r--]);
            }
        }
        swap(num[st], num[r]);
        return r;
    }
};
