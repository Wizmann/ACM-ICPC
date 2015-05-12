class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        int l = 1, r = numeric_limits<int>::max();
        
        while (l <= r) {
            int m = (l >> 1) + (r >> 1) + (l & r & 1);
            int cnt = count(L, m);
            if (cnt < k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
private:
    int count(const vector<int>& L, int l) {
        int cnt = 0;
        for (auto num: L) {
            cnt += num / l;
        }
        return cnt;
    }
};
