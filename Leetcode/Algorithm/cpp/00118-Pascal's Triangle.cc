class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        for (int i = 0; i < numRows; i++) {
            vector<int> t;
            if (i == 0) {
                t.push_back(1);
                res.push_back(t);
            } else {
                for (int j = 0; j <= i; j++) {
                    int x = 0;
                    if (j - 1 >= 0) x += res[i-1][j-1];
                    if (j < i) x += res[i-1][j];
                    t.push_back(x);
                }
                res.push_back(t);
            }
        }
        return res;
    }
};
