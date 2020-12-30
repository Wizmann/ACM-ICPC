class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        long long t = 1;
        for (int i = 1; i <= rowIndex; i++) {
            t *= (rowIndex - i + 1);
            t /= i;
            res.push_back(t);
        }
        return res;
    }
};
