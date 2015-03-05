// O(n * logn) time complexity
class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int p = i;
            while (p && A[parent(p)] > A[p]) {
                swap(A[parent(p)], A[p]);
                p = parent(p);
            }
        }
    }
private:
    int parent(int x) {
        return (x - 1) / 2;
    }
};

// O(n) time complexity
class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        int n = A.size();
        
        for(int i = flp2(n) - 1; i >= 0; i--) {
            down(A, i);
        }
    }
private:
    int down(vector<int> &A, int p) {
        int l = left(p);
        int r = right(p);
        int n = A.size();
        
        if (l < n && A[l] < A[p]) {
            swap(A[l], A[p]);
            down(A, l);
        }
        
        if (r < n && A[r] < A[p]) {
            swap(A[r], A[p]);
            down(A, r);
        }
    }            
        
    int left(int x) {
        return (x << 1) + 1;
    }
    int right(int x) {
        return (x << 1) + 2;
    }
    int flp2(int x) {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return x - (x >> 1);
    }
};

