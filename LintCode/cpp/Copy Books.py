class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int l = 0;
        int r = INF;
        
        while (l <= r) {
            int m = (l + r) >> 1;
            if (deal(pages, m) <= k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
private:
    int deal(const vector<int>& pages, int value) {
        int sum = 0;
        int cnt = 0;
        for (auto page: pages) {
            if (page > value) {
                return INF;
            }
            sum += page;
            if (sum > value) {
                cnt++;
                sum = page;
            }
        }
        if (sum) {
            cnt++;
        }
        return cnt;
    }
    
private:
    static const int INF = 0x3f3f3f3f;
};
