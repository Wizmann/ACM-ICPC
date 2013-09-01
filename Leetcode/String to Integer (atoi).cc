class Solution {
/*
 * 正常的atoi不是有异常就返回0么？
 * 这题出的人干事？
*/
public:
    int atoi(const char *str)
    {
        int sig = 1;
        int i = 0;
        long long ans = 0;
        
        while(str[i] == ' ') {
            ++i;
        }
        
        if (str[i] == '-') {
            i++;
            sig = -1;
        } else if (str[i] == '+') {
            i++;
        }
        
        for(i; str[i]; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                ans = ans * 10 + str[i] - '0';
            } else {
                break;
            }
        }
        ans *= sig;
        
        if (ans > INT_MAX) {
            ans = INT_MAX;
        }
        
        if (ans < INT_MIN) {
            ans = INT_MIN;
        }
        return ans;
    }
};
