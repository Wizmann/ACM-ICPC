class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.size();
        int tot = 0;
        for (int i = n - 1; i >= 0; i--) {
            tot += shifts[i];
            tot %= 26;
            S[i] = shift(S[i], tot);
        }
        return S;
    }
    
    char shift(char c, int delta) {
        return 'a' + ((c - 'a' + delta) % 26);
    }
};
