class RLEIterator {
public:
    RLEIterator(vector<int> A_) : cur(0), A(A_) {
        // pass
    }
    
    int next(int n) {
        while (cur < A.size() && A[cur] == 0) {
            cur += 2;
        }
        if (cur == A.size()) {
            return -1;
        }
        int d = min(n, A[cur]);
        n -= d;
        A[cur] -= d;
        
        if (n) {
            return next(n);
        } else {
            return A[cur + 1];
        }
    }
private:
    int cur;
    vector<int> A;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
