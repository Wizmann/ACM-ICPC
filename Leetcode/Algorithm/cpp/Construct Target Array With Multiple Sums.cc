https://leetcode.com/problems/construct-target-array-with-multiple-sums/

typedef long long llint;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        llint tot = accumulate(target.begin(), target.end(), 0LL);
        multiset<int> st;
        for (auto num : target) {
            st.insert(num);
        }
        
        while (tot > n) {
            int maxi = *st.rbegin();
            st.erase(--st.end());
            
            llint rem = tot - maxi;
            if (maxi - rem < 1 || rem == 0) {
                tot = -1;
                break;
            }
            maxi %= rem;
            if (maxi == 0) {
                maxi = rem;
            }
            st.insert(maxi);
            tot = rem + maxi;
        }
        
        return tot == n;
    }
};
