class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        for (int i = 1; i < n; i++) {
            A[i] += A[i - 1];
        }
        
        auto psum = [&](int l, int r) {
            assert(l >= 0 && r >= 0);
            assert(l < n && r < n);
            return A[r] - (l == 0? 0: A[l - 1]);
        };
        
        multiset<int> st;
        for (int i = M; i + L - 1 < n; i++) {
            st.insert(psum(i, i + L - 1));
        }
        
        int ans = 0;
        for (int i = M - 1; i < n; i++) {
            int a = psum(i - M + 1, i);
            if (!st.empty()) {
                int b = *st.rbegin();
                ans = max(ans, a + b);
            }
            
            if (i + L < n) {
                // cout << __LINE__ << ' ' << i + 1 << ' ' << i + L << endl;
                st.erase(st.find(psum(i + 1, i + L)));
            }
            
            if (i - M + 1 >= L - 1) {
                // cout << __LINE__ << ' ' << i - M + 1 << ' ' << i - M + 1 << endl;
                st.insert(psum(i - M + 1 - L + 1, i - M + 1));
            }
        }
        return ans;
    }
};
