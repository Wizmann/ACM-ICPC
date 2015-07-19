/*
class ExpressionTreeNode {
public:
    string symbol;
    ExpressionTreeNode *left, *right;
    ExpressionTreeNode(string symbol) {
        this->symbol = symbol;
        this->left = this->right = NULL;
    }
};
*/

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        return do_build(expression.begin(), expression.end());
    }
private:
    ExpressionTreeNode* do_build(
            vector<string>::iterator first,
            vector<string>::iterator last) {
        int lv = 0;
        
        string symbol = "#";
        int symbol_lv = 999999;
        auto pivot = first;
        
        for (auto iter = first; iter != last; ++iter) {
            if (*iter == "(") {
                lv++;
            } else if (*iter == ")") {
                lv--;
            } else if (is_symbol(*iter)) {
                if (lv < symbol_lv ||
						(lv == symbol_lv &&
							symbol_prior(*iter) <= symbol_prior(symbol))) {
                    symbol = *iter;
                    symbol_lv = lv;
                    pivot = iter;
                }
            }
        }
        
        if (symbol == "#") {
            for (auto iter = first; iter != last; ++iter) {
                if (*iter != "(" && *iter != ")") {
                    return new ExpressionTreeNode(*iter);
                }
            }
            return nullptr;
        } else {
            auto ptr = new ExpressionTreeNode(*pivot);
            if (symbol_lv) {
                first++;
                last--;
            }
            ptr->left = do_build(first, pivot);
            ptr->right = do_build(pivot + 1, last);
            return ptr;
        }
    }
    
    bool is_symbol(const string& symbol) {
        const unordered_set<string> symbols = {"+", "-", "*", "/"};
        return symbols.find(symbol) != symbols.end();
    }
    
    int symbol_prior(const string& symbol) {
        if (symbol == "+" || symbol == "-") {
            return 1;
        } else if (symbol == "*" || symbol == "/") {
            return 10;
        }
        return 999999;
    }
};
