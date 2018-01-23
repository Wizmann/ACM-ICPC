// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

const int SIZE = 66666;

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    vector<pair<int, int> > ps;
    int n = A.size();
    int m = C.size();
    
    int l = 0;
    int r = m;
    
    while (l <= r) {
        // cout << l << ' ' << r << endl;
        int mid = (l + r) >> 1;
        
        vector<int> prefix(SIZE, 0);
        
        for (int i = 0; i < mid; i++) {
            prefix[C[i]]++;
        }
        
        for (int i = 1; i < SIZE; i++) {
            prefix[i] += prefix[i - 1];
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (prefix[B[i]] - prefix[A[i] - 1] > 0) {
                cnt++;
            }
        }
        
        if (cnt == n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }   
    }
    if (l > m) {
        return -1;
    }
    return l;
}
