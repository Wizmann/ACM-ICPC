const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] += (i - 1 >= 0? matrix[i - 1][j] : 0) +
                                (j - 1 >= 0? matrix[i][j - 1] : 0) -
                                ((i - 1 >= 0 && j - 1 >= 0)? matrix[i - 1][j - 1]: 0);
                                
            }
        }
        
        int maxi = -INF;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                set<int> st;
                st.insert(0);
                for (int k = 0; k < n; k++) {
                    int prefix = matrix[k][i] - (j - 1 >= 0? matrix[k][j - 1]: 0);
                    int target = prefix - K;
                    auto iter = st.lower_bound(target);
                    // cout << prefix << ' ' << target << ' ' << *iter << endl;
                    if (iter != st.end()) {
                        int sum = prefix - *iter;
                        if (sum <= K) {
                            maxi = max(maxi, sum);
                        }
                    }
                    st.insert(prefix);
                    assert(maxi <= K);
                }
            }
        }
        return maxi;
    }
};
