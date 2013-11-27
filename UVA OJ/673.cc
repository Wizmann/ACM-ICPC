//Result: Wizmann   UVA 673 Accepted    0 KB    52 ms   C++ 4.5.3   1149 B  
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t SIZE = 1024;

char buffer[SIZE];
stack<char> st;

inline char getopp(char x)
{
    switch(x) {
        case ']': return '[';
        case ')': return '(';
        case '}': return '{';
        default : while(1){}
    }
    return '\0';
}

bool solve()
{
    st = stack<char>();
    for (int i = 0; buffer[i]; i++)
    {
        if (buffer[i] == '(' ||
            buffer[i] == '[' ||
            buffer[i] == '{') {
            st.push(buffer[i]);
        } else if (buffer[i] == ')' ||
                   buffer[i] == ']' ||
                   buffer[i] == '}') {
            char x = getopp(buffer[i]);
            if (!st.empty() && st.top() == x) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}


int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    fgets(buffer, SIZE, stdin);
    while (T--) {
        fgets(buffer, SIZE, stdin);
        //print(buffer);
        puts(solve()? "Yes" : "No");
    }
    return 0;
}
