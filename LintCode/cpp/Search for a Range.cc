class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        if (A.empty()) {
            return {-1, -1};
        }
        auto a = my_lower_bound(A.begin(), A.end(), target);
        auto b = my_upper_bound(A.begin(), A.end(), target);
        
        if (a != A.end() && *a == target) {
            return {a - A.begin(), b - A.begin() - 1};
        } else {
            return {-1, -1};
        }
    }
private:
    template <typename iter>
    iter my_lower_bound(iter st, iter end, int target) {
        iter l = st;
        iter r = end - 1;
        
        while (l <= r) {
            iter m = l + (r - l) / 2;
            if (*m >= target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    
    template <typename iter>
    iter my_upper_bound(iter st, iter end, int target) {
        iter l = st;
        iter r = end - 1;
        
        while (l <= r) {
            iter m = l + (r - l) / 2;
            if (*m > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
