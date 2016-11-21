class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int n = num1.size();
        int m = num2.size();
        string num3;
        
        int g = 0;
        for (int i = 0; i < max(n, m); i++) {
            int a = i < n? num1[i] - '0': 0;
            int b = i < m? num2[i] - '0': 0;
            
            num3 += to_string((a + b + g) % 10);
            g = (a + b + g) / 10;
        }
        if (g) {
            num3 += "1";
        }
        reverse(num3.begin(), num3.end());
        return num3;
    }
};
