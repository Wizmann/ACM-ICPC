class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        int n = A.size();
        if (n <= 0) {
            return "";
        }
        offset %= n;
        string X = A.substr(0, n - offset);
        string Y = A.substr(n - offset, offset);
        reverse(X.begin(), X.end());
        reverse(Y.begin(), Y.end());
        string Z = X + Y;
        reverse(Z.begin(), Z.end());
        return Z;
    }
};
