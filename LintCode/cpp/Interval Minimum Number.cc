/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        n = A.size();
        res.clear();
        init_rmq(A, n);
        for (const auto& q: queries) {
            int a = q.start;
            int b = q.end;
            
            res.push_back(rmq_query(a, b));
        }
        return res;
    }
private:
    void init_rmq(vector<int> &A, int n) {
        mini.clear();
        mini.resize(MAXI + 3);
        for (auto& vec: mini) {
            vec.resize(n);
        }
        
        for (int i = 0; i < n; i++) {
            mini[0][i] = A[i];
        }
        
        for (int i = 1; i < MAXI; i++) {
            for (int j = 0; j < n; j++) {
                mini[i][j] = min(
                    mini[i - 1][j],
                    mini[i - 1][min(n - 1, j + pow2(i - 1))]
                );
            }
        }
    }
    
    int rmq_query(int l, int r) {
        int u = log2(r - l + 1);
        int a = mini[u][l];
        int b = mini[u][r - pow2(u) + 1];
        return min(a, b);
    }
private:
    int pow2(int x) {
        return 1 << x;
    }
    int log2(int x) {
        for (int i = 0; i <= MAXI; i++) {
            if ((1 << i) > x) {
                return i - 1;
            }
        }
        return -1;
    }
private:
    vector<int> res;
    vector<vector<int>> mini;
    int n;
private:
    static const int MAXI = 20;
};
