class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return check(s1, s2) || check(s2, s1);
    }
    
    bool check(const string& s1, const string& s2) {
        assert(s1.size() == s2.size());
        const int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] < s2[i]) {
                return false;
            }
        }
        return true;
    }
};
