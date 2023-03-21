#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

enum class TokenType {
    Op_Plus,
    Op_Minus,
    Op_Multi,
    Op_Div,
    Op_Lp,
    Op_Rp,
    Num
};

struct Token {
    TokenType type;
    double value;
};

double eval(Token* tokens, int n) {
    if (n == 1) {
        assert(tokens[0].type == TokenType::Num);
        return tokens[0].value;
    }

    for (int i = 0; i < n; i++) {
        if (tokens[i].type == TokenType::Op_Plus || tokens[i].type == TokenType::Op_Minus) {
            double l = eval(tokens, i);
            if (tokens[i].type == TokenType::Op_Minus) {
                tokens[i + 1].value *= -1;
            }
            double r = eval(tokens + i + 1, n - i - 1);
            return l + r;
        }
    }

    assert(tokens[0].type == TokenType::Num);
    double v = tokens[0].value;;
    for (int i = 1; i < n; i += 2) {
        assert(tokens[i + 1].type == TokenType::Num);
        if (tokens[i].type == TokenType::Op_Multi) {
            v *= tokens[i + 1].value;
        } else if (tokens[i].type == TokenType::Op_Div) {
            v /= tokens[i + 1].value;
        } else {
            assert(false);
        }
    }

    return v;
}

int main() {
    string s;
    getline(cin, s);

    s = "( " + s + " ) ";

    vector<Token> tokens;
    {
        string token;
        for (auto c: s) {
            if (c == ' ') {
                if (!token.empty()) {
                    if ('0' <= *token.rbegin() && *token.rbegin() <= '9') {
                        tokens.push_back({TokenType::Num, atof(token.c_str())});
                    } else {
                        assert(token.size() == 1);
                        switch (token[0]) {
                            case '+':
                                tokens.push_back({TokenType::Op_Plus, NAN});
                                break;
                            case '-':
                                tokens.push_back({TokenType::Op_Minus, NAN});
                                break;
                            case '*':
                                tokens.push_back({TokenType::Op_Multi, NAN});
                                break;
                            case '/':
                                tokens.push_back({TokenType::Op_Div, NAN});
                                break;
                            case '(':
                                tokens.push_back({TokenType::Op_Lp, NAN});
                                break;
                            case ')':
                                tokens.push_back({TokenType::Op_Rp, NAN});
                                break;
                            default:
                                assert(false);
                                break;
                        }
                    }
                    token = "";
                }
                continue;
            }
            token += c;
        }
    }

    vector<int> lp;
    vector<Token> st;

    for (auto& token : tokens) {
        if (token.type == TokenType::Op_Rp) {
            int l = *lp.rbegin();
            lp.pop_back();
            double v = eval(st.data() + l + 1, st.size() - l - 1);
            st.resize(l);
            st.push_back({TokenType::Num, v});
        } else {
            if (token.type == TokenType::Op_Lp) {
                lp.push_back(st.size());
            }
            st.push_back(token);
        }
    }

    assert(st.size() == 1);
    printf("%.6lf\n", st[0].value);

    return 0;
}

/*

^^^TEST^^^
( 11.0  + 12.0  ) * ( 24.0 + 35.0 )
-------------
1357.000000
$$$TEST$$$

^^^TEST^^^
9 * 10 - +2 - -3
-------------
91.000000
$$$TEST$$$

*/
