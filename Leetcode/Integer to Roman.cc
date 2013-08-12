class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int base = 10;
        while (num < base/10) {
            int x = num % base / (base / 10);
            ans += _digit_to_roman(x);
            base *= 10;
        }
        return ans;
    }
    
    string _digit_to_roman(int num)
    {
        string one, five, ten;
        int base = -1;
        if (num > 0 && num < 10) {
            one  = "I";
            five = "V";
            ten  = "X";
            base = 1;
        } else if (num >= 10 && num < 100) {
            one  = "X";
            five = "L";
            ten  = "C";
            base = 10;
        } else if (num >= 100 && num < 1000) {
            one  = "C";
            five = "D";
            ten  = "M";
        } else if (num >= 1000 && num < 10000) {
            one  = "M";
            five = "v";
            ten  = "x";
        } else {
            return "";
        }
        
        while (num >= 10) {
            num /= 10;
        }
        
        string ans = "";
        switch(num) {
            case 1: ans = one; break;
            case 2: ans = one + one; break;
            case 3: ans = one + one + one; break;
            case 4: ans = one + five; break;
            case 5: ans = five; break;
            case 6: ans = five + one; break;
            case 7: ans = five + one + one; break;
            case 8: ans = five + one + one + one; break;
            case 9: ans = one + ten; break;
            case 10: ans = ten; break;
            default: ans = ""; break;
        }
        return ans;
    }
}; 
