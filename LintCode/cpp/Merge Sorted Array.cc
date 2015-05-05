class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int na = A.size();
        int nb = B.size();
        
        vector<int> C;
        
        int i = 0;
        int j = 0;
        
        while (i < na && j < nb) {
            if (A[i] < B[j]) {
                C.push_back(A[i]);
                i++;
            } else {
                C.push_back(B[j]);
                j++;
            }
        }
        
        while (i < na) {
            C.push_back(A[i++]);
        }
        while (j < nb) {
            C.push_back(B[j++]);
        }
        return C;
    }
};
