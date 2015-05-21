class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        vector<int> Qs;
        res.clear();
        for (int i = 0; i < n; i++) {
            Qs.push_back(i);
        }
        int cnt = 1;
        do {
            bool flag = detect(Qs);
            if (flag) {
                make_board(Qs);
            }
        } while (next_permutation(Qs.begin(), Qs.end()));
        return res;
    }
private:
    bool detect(const vector<int>& Qs) {
        int n = Qs.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(i - j) == abs(Qs[i] - Qs[j])) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void make_board(const vector<int>& Qs) {
        int n = Qs.size();
        vector<string> tmp;
        for (int i = 0; i < n; i++) {
            string line(n, '.');
            line[Qs[i]] = 'Q';
            tmp.push_back(line);
        }
        res.push_back(tmp);
    }
private:
    vector<vector<string> > res;
};

