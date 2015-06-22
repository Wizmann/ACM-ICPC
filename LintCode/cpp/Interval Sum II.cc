class BinaryIndexedTree {
public:
    BinaryIndexedTree() {}
    
    BinaryIndexedTree(int n) {
        _bit.resize(n + 1);
        _array.resize(n + 1);
    }
    
    long long sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
    
    long long sum(int a) {
        long long res = 0;
        while (a) {
            res += _bit[a];
            a -= lowbit(a);
        }
        return res;
    }
    
    void modify(int ptr, int value) {
        int prev = _array[ptr];
        int diff = value - prev;
        _array[ptr] = value;
        while (ptr < _bit.size()) {
            _bit[ptr] += diff;
            ptr += lowbit(ptr);
        }
    }
private:
    int lowbit(int x) {
        return x & (-x);
    }
private:
    vector<int> _bit;
    vector<int> _array;
};

class Solution {
public:
    /* you may need to use some attributes here */
    

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        int n = A.size();
        _bit = BinaryIndexedTree(n);
        for (int i = 0; i < n; i++) {
            _bit.modify(i + 1, A[i]);
        }
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        return _bit.sum(start + 1, end + 1);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        _bit.modify(index + 1, value);
    }
private:
    BinaryIndexedTree _bit;
};

