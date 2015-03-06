class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        int a = 0;
        for (auto c: str) {
            int u = c - 'a';
            if (a & (1 << u)) {
                return false;
            }
            a |= (1 << u);
        }
        return true;
    }
};
