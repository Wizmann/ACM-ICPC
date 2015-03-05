class Solution {
public:
    string DeleteDigits(string A, int k) {
        while (k > 0) {
            for (int i = 0; i < A.size(); i++) {
                if (i == A.size() - 1 || A[i] > A[i + 1]) {
                    A.erase(i, 1);
                    break;
                }
            }
            k--;
        }
        
        auto it = A.begin();
        while (*it == '0') {
            it = A.erase(it);
        }

        return A;
    }
};
