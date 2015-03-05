class Solution {
public:
    /**
     * @param A: An integer array.
     * @return an integer array
     */
    vector<int> rerange(vector<int> &A) {
        int idx = partition(A, 0);
        int neg_num = idx;
        int pos_num = A.size() - neg_num;
        
        int l = 0, r = A.size() - 1;
        if (neg_num > pos_num) {
            l++;
        } else if (neg_num < pos_num) {
            r--;
        }

        while (l < r) {
            swap(A[l], A[r]);
            l += 2;
            r -= 2;
        }

        return A;
    }
private:
    int partition(vector<int> &A, int pivot) {
        int l = 0, r = A.size() - 1;
        while (l < r) {
            while (l < r && A[l] < pivot) {
                l++;
            }
            while (l < r && A[r] > pivot) {
                r--;
            }
            if (l < r) {
                swap(A[l], A[r]);
                l++;
                r--;
            }
        }
        return l;
    }
};
