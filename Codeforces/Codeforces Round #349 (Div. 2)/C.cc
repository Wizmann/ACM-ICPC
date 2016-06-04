#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

// #define DEBUG

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 11111;

string s;
int n;
char dp2[SIZE];
char dp3[SIZE];

set<string> st;

void solve() {
    dp2[1] = dp3[2] = 1;
    st.insert(s.substr(0, 2));
    st.insert(s.substr(0, 3));
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0) {
            string cur2 = s.substr(i - 1, 2);
            if (i - 2 >= 0 && dp3[i - 2]) {
                dp2[i] = 1;
                st.insert(cur2);
            } else if (i - 3 >= 0 && dp2[i - 2]) {
                string pre2 = s.substr(i - 3, 2);
                if (cur2 != pre2) {
                    dp2[i] = 1;
                    st.insert(cur2);
                }
            }
        }

        if (i - 2 >= 0) {
            string cur3 = s.substr(i - 2, 3);
            if (i - 3 >= 0 && dp2[i - 3]) {
                dp3[i] = 1;
                st.insert(cur3);
            } else if (i - 5 >= 0 && dp3[i - 3]) {
                string pre3 = s.substr(i - 5, 3);
                if (cur3 != pre3) {
                    dp3[i] = 1;
                    st.insert(cur3);
                }
            }
        }
    }
}

int main() {
    input(s);
    if (s.size() <= 6) {
        puts("0");
        return 0;
    }

    s = s.substr(5);
    
    #ifdef DEBUG
    print(s);
    #endif
    
    reverse(s.begin(), s.end());
    n = s.size();
    memset(dp2, 0, sizeof(dp2));
    memset(dp3, 0, sizeof(dp3));

    solve();

    print(st.size());
    vector<string> res;
    copy(st.begin(), st.end(), back_inserter(res));
    for (auto& s: res) {
        reverse(s.begin(), s.end());
    }
    sort(res.begin(), res.end());
    
    for (auto& s: res) {
        puts(s.c_str());
    }

    return 0;
}
