class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num.size();
        return kth_element(num, 0, n, n / 2 + 1);
    }
private:
    int partition(vector<int>& vec, int l, int r) {
        int ll = 0;
        int rr = r - l - 1;
        int pivot = vec[l];
        int ptr = 0;
        while (ll <= rr) {
            while (ll <= rr && 
                    (vec[l + ll] < pivot || 
                            (vec[l + ll] == pivot && ptr == 0))) {
                ptr ^= (vec[l + ll] == pivot);
                ll++;
            }
            while (ll <= rr &&
                    (vec[l + rr] > pivot ||
                            (vec[l + rr] == pivot && ptr == 1))) {
                ptr ^= (vec[l + rr] == pivot);
                rr--;
            }
            if (ll <= rr) {
                swap(vec[l + ll], vec[l + rr]);
                ll++;
                rr--;
            }
        }
        swap(vec[l], vec[l + rr]);
        return rr;
    }
    
    int kth_element(vector<int>& vec, int l, int r, int k) {
        int p = partition(vec, l, r);
        if (p + 1 == k) {
            return vec[l + p];
        } else if (p + 1 < k) {
            return kth_element(vec, l + p + 1, r, k - p - 1);
        } else {
            return kth_element(vec, l, l + p, k);
        }
    }
};
