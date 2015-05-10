class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        _bit.clear();
        _bit.resize(SIZE);
        fill(_bit.begin(), _bit.end(), 0);
        
        for (auto a: A) {
            bit_add(a, 1);
        }
        
        vector<int> res;
        for (auto q: queries) {
            res.push_back(bit_sum(q - 1));
        }
        return res;
    }
private:
    inline int lowbit(int x) {return x & (-x);}
    void bit_add(int pos, int value) {
        while (pos < SIZE) {
            _bit[pos] += value;
            pos += lowbit(pos);
        }
    }
    int bit_sum(int pos) {
        int res = 0;
        while (pos) {
            res += _bit[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
private:
    vector<int> _bit;
private:
    static const int SIZE = 12345;
};
