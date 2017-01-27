class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        expression.push_back("#");
        stack<int> nums;
        stack<char> symbols;
        
        for (auto& item: expression) {
            int p = prior(item[0]);
            if (p == NOT_SYMBOL) {
                nums.push(strtol(item.c_str(), NULL, 10)); 
                continue;
            }
            
            if (symbols.empty() || prior(symbols.top()) < p) {
                symbols.push(item[0]);
                continue;
            }
            
            while (!symbols.empty() && prior(symbols.top()) >= p) {
                char s = symbols.top();
                symbols.pop();
                
                if (s == '(' && item[0] == ')') {
                    break;
                }
                if (s == '(') {
                    symbols.push('(');
                    break;
                }
                    
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                    
                nums.push(calc(a, b, s));
            }
            if (item[0] != ')') {
                symbols.push(item[0]);
            }
        }
        return nums.empty()? 0: nums.top();
    }
private:
    int prior(char symbol) {
        switch (symbol) {
            case '(':
                return 999;   
            case '*': case '/':
                return 99;
            case '+': case '-':
                return 9;
            case '#': case ')':
                return -1;
        }
        return NOT_SYMBOL;
    }
    
    int calc(int a, int b, char s) {
        switch (s) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return -1;
    }
private:
    static const int NOT_SYMBOL = -999;
};
