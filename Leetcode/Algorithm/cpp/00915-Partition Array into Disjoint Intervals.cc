class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        multiset<int> l, r;
        int n = A.size();
        
        for (auto num: A) {
            r.insert(num);
        }
        
        for (int i = 0; i < n - 1; i++) {
            int cur = A[i];
            
            l.insert(cur);
            r.erase(r.find(cur));
            
            if (*l.rbegin() <= *r.begin()) {
                return i + 1;
            }
        }
        return -1;
    }
};
