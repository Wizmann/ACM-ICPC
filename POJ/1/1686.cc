//Result: wizmann   1686    Accepted    736K    0MS G++ 4147B   2014-03-18 13:54:49
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define print(x) cout << x << "\n"
#define input(x) cin >> x

const int VARS = 256;
const int INF = 0x3f3f3f3f;

/////

int vars[VARS];

bool is_prime(int v)
{
    for (int i = 2; i < v/2; i++) {
        if (v % i == 0) return false;
    }
    return true;
}

void init_vars()
{
    for (int i = 11, j = 0; j < VARS; j++) {
        while (!is_prime(i)) i++;
        vars[j] = i++;
    }
}

/////

inline bool isop(char c)
{
    switch(c) {
        case '+':
        case '-':
        case '*': 
        case '(':
        case ')':return true;
    }
    return false;
}

inline int op_pri(char c)
{
    switch(c) {
        case '/':
        case '*': return 999;
        case '+':
        case '-': return 99;
    }
    return -1;
}

struct Element {
    int num;
    char op;

    Element()
    {
        num = INF;
        op = 0;
    }

    inline bool is_num() const { return num != INF; }
    inline bool is_op()  const { return op; }

    static Element set_num(int v)
    {
        Element e;
        e.num = v;
        return e;
    }

    static Element set_var(char c)
    {
        Element e;
        e.num = vars[int(c)];
        return e;
    }

    static Element set_op(char c)
    {
        Element e;
        e.op = c;
        return e;
    }
};

void toReversePolish(const string& exps, vector<Element>& rpexp)
{
    stack<char> st;
    int len = exps.length();
    rpexp.clear();
    for (int i = 0; i < len; i++) {
        char c = exps[i];
        if (isdigit(c)) {
            rpexp.push_back(Element::set_num(c - '0'));
        } else if (isalpha(c)) {
            rpexp.push_back(Element::set_var(c));
        } else if (isop(c)) {
            if (c == '(' || st.empty()) {
                st.push(c);
            } else if (c == ')') {
                while (st.top() != '(') {
                    rpexp.push_back(Element::set_op(st.top()));
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && op_pri(c) <= op_pri(st.top())) {
                    rpexp.push_back(Element::set_op(st.top()));
                    st.pop();
                }
                st.push(c);
            }
        }
    }
    while (!st.empty()) {
        rpexp.push_back(Element::set_op(st.top()));
        st.pop();
    }
}

Element do_calc(Element& a, char op, Element& b)
{
    Element e;
    switch(op) {
        case '+':
            e.num = a.num + b.num;
            break;
        case '-':
            e.num = a.num - b.num;
            break;
        case '*':
            e.num = a.num * b.num;
            break;
        default:
            puts("FAIL LOUDLY!");
            while(1) {/* MAKE A TLE TO SHOW THIS ERROR WHEN JUDGE ONLINE */};
            break;
    }
    return e;
}

Element calcReversePolish(const vector<Element>& rpexp)
{
    int len = rpexp.size();
    stack<Element> st;
    for (int i = 0; i < len; i++) {
        if (!rpexp[i].is_op()) {
            st.push(rpexp[i]);
        } else {
            Element b = st.top();
            st.pop();
            Element a = st.top();
            st.pop();
            
            Element e = do_calc(a, rpexp[i].op, b);
            st.push(e);
        }
    }
    return st.top();
}

Element calc(const string& exps)
{
    vector<Element> rpexp;
    toReversePolish(exps, rpexp);
    return calcReversePolish(rpexp);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    string expa, expb;
    
    input(T);
    getline(cin, expa);
    init_vars();
    
    while (T--) {
        getline(cin, expa);
        getline(cin, expb);
//        print(expa);
//        print(expb);
        Element resa = calc(expa);
        Element resb = calc(expb);
        puts(resa.num == resb.num? "YES": "NO");
    }
    return 0;
}
