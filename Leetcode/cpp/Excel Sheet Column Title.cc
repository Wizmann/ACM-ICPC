class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) {
            return "";
        }
        int x = n % 26;
        char c = x != 0? 'A' + x - 1: 'Z';
        n = n / 26;
        if (x == 0) {
            n--;
        }
        return convertToTitle(n) + c;
    }
};
