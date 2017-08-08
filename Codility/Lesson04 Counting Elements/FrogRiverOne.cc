// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <set>

int solution(int X, vector<int> &A) {
    int n = A.size();
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(A[i]);
        if (st.size() == X) {
            return i;
        }
    }
    return -1;
}
