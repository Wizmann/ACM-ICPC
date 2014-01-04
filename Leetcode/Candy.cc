class Solution {
public:
    int candy(vector<int> &ratings) {
        size_t n = ratings.size();
        vector<node> children;
        for (size_t i = 0; i < n; i++) {
            children.push_back(node(i, ratings[i]));
        }
        sort(children.begin(), children.end());
        
        int ans = 0;
        vector<int> candy;
        candy.resize(n, 0);
        
        for (size_t i = 0; i < n; i++) {
            int pos = children[i].pos;
            int rate = children[i].rate;
            
            int maxi = 0;
            
            if (pos - 1 >= 0 && ratings[pos - 1] < rate) {
                maxi = max(maxi, candy[pos - 1]);
            }
            if (pos + 1 < n && ratings[pos + 1] < rate) {
                maxi = max(maxi, candy[pos + 1]);
            }
            
            ++maxi;
            candy[pos] = maxi;
            ans += maxi;
        }
        return ans;
    }
private:
    struct node {
        int pos, rate;
        
        node(){}
        node(int ipos, int irate) : pos(ipos), rate(irate) {}
        
        bool operator < (const node& a) const {
            return rate < a.rate;
        }
    };
};
