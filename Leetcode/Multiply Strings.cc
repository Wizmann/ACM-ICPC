class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        num1 += "000";
        num2 += "000";
        
        string res(SIZE, '0');
        for (int i = 0; i < (int)num1.size(); i++) {
            int g = 0;
            for (int j = 0; j < (int)num2.size(); j++) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int c = a * b + g;
                int d = res[j + i] - '0';
                
                res[j + i] = (d + c) % 10 + '0';
                g = (d + c) / 10;
            }
        }
        reverse(res.begin(), res.end());
        string tt;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == '0' && tt.empty()) continue;
            else {
                tt += res[i];
            }
        }
        return tt.empty()? "0": tt;
    }
    
    static const int SIZE = 1024;
};
