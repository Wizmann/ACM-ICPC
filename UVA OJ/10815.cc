// Result: 10815    Andy's First Dictionary Accepted    C++ 0.039   2013-10-30 11:00:18
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <cctype>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t STR_SIZE = 1024;

int main()
{
    freopen("input.txt", "r", stdin);
    
    char line[STR_SIZE];
    set<string> st;
    string ss;

    while (fgets(line, STR_SIZE, stdin)) {
        for (int i = 0; line[i]; i++) {
            if (isalpha(line[i])) {
                if (isupper(line[i])) {
                    line[i] ^= 32;
                }
                ss += line[i];
            } else {
                if (!ss.empty()) {
                    st.insert(ss);
                    ss = string();
                }
            }
        }
    }
    for (set<string>::iterator iter = st.begin();
            iter != st.end();
            ++iter) {
        print(*iter);
    }
    return 0;
}
