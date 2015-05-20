class BinaryIndexedTree {
public:
    BinaryIndexedTree(int size): _size(size) {
        _bit.resize(size + 1);
    }
    
    void add(int pos, int value) {
        while (pos < _size) {
            _bit[pos] += value;
            pos += lowbit(pos);
        }
    }
    
    int sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int sum(int pos) {
        int res = 0;
        while (pos) {
            res += _bit[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
    inline int lowbit(int x) { return x & (-x); }
private:
    int _size;
    vector<int> _bit;
};


class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        int n = A.size();
        vector<int> res;
        BinaryIndexedTree bit(102400);
        for (int i = 0; i < n; i++) {
            int v = A[i] + 1;
            res.push_back(bit.sum(1, v - 1));
            bit.add(v, 1);
        }
        return res;
    }
};
