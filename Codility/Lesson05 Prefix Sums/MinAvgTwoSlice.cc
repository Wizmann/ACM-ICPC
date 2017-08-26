// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

const int INF = 0x3f3f3f3f;

int solution(vector<int> &A) {
    int n = A.size();
    double mini = INF;
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            double cur = (A[i] + A[i + 1]) / 2.;
            if (cur < mini) {
                res = i;
                mini = cur;
            }
        }
        
        if (i + 2 < n) {
            double cur = (A[i] + A[i + 1] + A[i + 2]) / 3.;
            if (cur < mini) {
                res = i;
                mini = cur;
            }
        }
    }
    return res;            
}
