// 中序表达式转逆波兰式的步骤
// 1. 声明一个运算符栈S，声明一个后辍表达式空序列V
// 2. 依次从中序表达式取操作数/运算符
//    - if 取出的是操作数 => 直接进入序列V
//    - if 取出的是运算符
//        - if S是空的 => 入栈S
//        - if S不是空的 && 当前运算符优先级大于S栈顶运算符 => 入栈S
//        - if 当前运算符为'(' => 入栈S
//        - if 当前运算符为')' => 
//              while (S.top() != '(') {
//                  V.push_back(S.top());
//                  S.pop();
//              }
//              S.pop(); //抛弃'('
// 3. 将S中剩余的操作符依次插入V

// TEST CASES
// 4
// 2*6-(23+7)/(1+2)
// 3+5*8
// (3+5)*8
// (23+34*45/(5+6+7))

// ANSWER
// 2
// 43
// 64
// 108

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <vector>
#include <cctype>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Object {
    enum {NUMBER, OPERATOR};
    typedef int type;
    int val; 
    type tp;
    Object(){}
    Object(int ival, type itp): \
        val(ival), tp(itp) {}

    string show() {
        char buffer[10];
        if (tp == NUMBER) {
            sprintf(buffer, "%d", val);
        } else {
            sprintf(buffer, "%c", (char)val);
        }
        return string(buffer);
    }
};

int opt_pri(const Object& x)
{
    if (x.tp != Object::OPERATOR) return -1;
    char t = char(x.val);
    
    switch (t) {
        case '*':
        case '/': return 999;
        case '+':
        case '-': return 99;
    }
    return -1;
}

void infix_to_suffix(const vector<Object>& infix, vector<Object>& suffix)
{
    stack<Object> st;
    suffix.clear();
    for (int i = 0; i < (int)infix.size(); i++) {
        if (infix[i].tp == Object::NUMBER) {
            suffix.push_back(infix[i]);
        } else {
            if ('(' == char(infix[i].val)) {
                st.push(infix[i]);
            } else if (')' == char(infix[i].val)) {
                while ('(' != char(st.top().val)) {
                    suffix.push_back(st.top());
                    st.pop();
                }
                st.pop();
            } else if (st.empty() || 
                    opt_pri(st.top()) < opt_pri(infix[i])) {
                st.push(infix[i]);
            } else {
                while (opt_pri(infix[i]) <= opt_pri(st.top())) {
                    suffix.push_back(st.top());
                    st.pop();
                    if (st.empty()) break;
                }
                st.push(infix[i]);
            }
        }
    }
    while (!st.empty()) {
        suffix.push_back(st.top());
        st.pop();
    }
}

void parse(const char* buffer, vector<Object>& infix)
{
    int g = -1;
    int len = strlen(buffer);
    infix.clear();
    for (int i = 0; i <= len; i++) {
        if (isdigit(buffer[i])) {
            if (g == -1) g = 0;
            g = g * 10 + buffer[i] - '0';
        } else {
            if (g != -1) {
                infix.push_back(Object(g, Object::NUMBER));
                g = -1;
            }

            if (buffer[i]) {
                infix.push_back(Object(int(buffer[i]), Object::OPERATOR));
            }
        }
    }
}

int calc_suffix(const vector<Object>& suffix)
{
    stack<Object> st;
    for (size_t i = 0; i < suffix.size(); i++) {
        if (suffix[i].tp == Object::NUMBER) {
            st.push(suffix[i]);
        } else {
            Object a = st.top();
            st.pop();
            Object b = st.top();
            st.pop();
            
            int v = -1;
            switch (char(suffix[i].val)) {
                case '+': v = b.val + a.val; break;
                case '-': v = b.val - a.val; break;
                case '*': v = b.val * a.val; break;
                case '/': v = b.val / a.val; break;
            }
            st.push(Object(v, Object::NUMBER));
        }
    }
    return st.top().val;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    char buffer[1024];
    input(T);
    while (T--) {
        vector<Object> infix;
        vector<Object> suffix;
        input(buffer);
        parse(buffer, infix);
        
        /*
        for (int i = 0; i < (int)infix.size(); i++) {
            printf("%s ", infix[i].show().c_str());
        }
        puts("");
        */
        
        infix_to_suffix(infix, suffix);
        
        /*
        for (int i = 0; i < (int)suffix.size(); i++) {
            printf("%s ", suffix[i].show().c_str());
        }
        puts("");
        */
        
        print(calc_suffix(suffix));
    }
    return 0;
}
