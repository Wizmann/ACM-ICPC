//Result: 3457  204  通过 10 ms   944 KB  GNU C++  1123 B 2014-03-18 21:26:20 test#wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <ctime>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    string exp;
    getline(cin, exp);
    
    while (T--) {
        getline(cin, exp);
        stack<char> st;
        bool flag = true;
        int len = exp.length();
        //print(exp);
        for (int i = 0; i < len; i++) {
            if (exp[i] == '(') {
                st.push('(');
            } else if (exp[i] == ')') {
                char p = '#';
                if (!st.empty()) {
                    p = st.top();
                    st.pop();
                }
                if (p != '(') {
                    flag = false;
                    break;
                }
            }
        }
        if (flag && st.empty()) puts("yes");
        else puts("no");
    }
    return 0;
}
