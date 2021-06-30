class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        const int n = str.size();
        if (n == 0) {
            return;
        }
        offset %= n;
        str = str.substr(n - offset) + str.substr(0, n - offset);
    }
};
