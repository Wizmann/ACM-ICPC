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
    typedef long long llint;
public:
    vector<llint> intervalSum(vector<int> &A, vector<Interval> &queries) {
        make_bit(A);
        vector<llint> res;
        for (auto item: queries) {
            res.push_back(
                bit_query(item.start + 1, item.end + 1)
            );
        }
        return res;
    }
private:
    llint bit_query(int st, int end) {
        return bit_sum(end) - bit_sum(st - 1);
    }
    
    llint bit_sum(int pos) {
        llint res = 0;

        while (pos) {
            res += _bit[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
    
    void make_bit(vector<int> &A) {
        n = A.size() + 233;
        
        _bit.clear();
        _bit.resize(n);
        fill(_bit.begin(), _bit.end(), 0);
        
        for (int i = 0; i < n; i++) {
            bit_add(A[i], i + 1);
        }
    }
    
    void bit_add(int value, int p) {
        while (p < n) {
            _bit[p] += value;
            p += lowbit(p);
        }
    }
private:
    inline int lowbit(int x) { return x & (-x); }
private:
    int n;
    vector<llint> _bit;
};
