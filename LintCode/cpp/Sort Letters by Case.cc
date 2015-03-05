class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        int n = letters.size();
        int l = 0;
        int r = n - 1;
        
        while (l < r) {
            while (l < r && islower(letters[l])) {
                l++;
            }
            while (l < r && isupper(letters[r])) {
                r--;
            }
            if (l < r) {
                swap(letters[l], letters[r]);
                l++;
                r--;
            }
        }
    }
};

