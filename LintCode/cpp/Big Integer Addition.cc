class Solution {
public:
    /*
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int g = 0;
        int n = num1.size();
        int m = num2.size();
        
        for (int i = 0, j = 0; i < n || j < m; i++, j++) {
            int a = i < n? num1[i] - '0': 0;
            int b = j < m? num2[j] - '0': 0;
            
            res += to_string((a + b + g) % 10);
            g = (a + b + g) / 10;
        }
        if (g) {
            res += to_string(g);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
