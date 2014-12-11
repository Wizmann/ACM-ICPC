class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        memset(cnt, 0, sizeof(cnt));
        for (auto c: A) {
            cnt[c]++;
        }
        bool flag = true;
        for (auto c: B) {
            cnt[c]--;
            flag &= (cnt[c] >= 0);
        }
        return flag;
    }
private:
    static const int SIZE = 256;
    int cnt[SIZE];
};

