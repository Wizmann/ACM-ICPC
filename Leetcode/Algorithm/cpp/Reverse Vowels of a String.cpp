class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            while (l <= r && !is_vowel(s[l])) {
                l++;
            }
            while (l <= r && !is_vowel(s[r])) {
                r--;
            }
            if (l <= r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
private:
    bool is_vowel(char c) {
        switch(c) {
            case 'a': case 'A':
            case 'e': case 'E':
            case 'i': case 'I':
            case 'o': case 'O':
            case 'u': case 'U':
                return true;
        }
        return false;
    }
};
