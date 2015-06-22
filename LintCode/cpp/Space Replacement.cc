class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        if (length == 0) {
            return 0;
        }
        int space = 0;
        for (int i = 0; i < length; i++) {
            if (string[i] == ' ') {
                space++;
            }
        }
        
        int p = length + space * 2;
        int q = length;
        string[p + 1] = '\0';
        
        while (q >= 0) {
            if (string[q] != ' ') {
                string[p--] = string[q--];
                continue;
            }
            
            string[p--] = '0';
            string[p--] = '2';
            string[p--] = '%%';
            q--;
        }
        return length + space * 2;
    }
};  
