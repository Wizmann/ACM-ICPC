#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

using namespace std;

#define print(x) cout << x << endl

typedef long long llint;

int readint()  
{  
    char c;  
    int ret = 0;  

    while((c = getchar()) < '0' || c > '9') {
        // pass
    }

    while(c >= '0' && c <= '9') {
        ret = ret * 10 +(c - '0');
        c = getchar();
    }
    return ret;
} 

class Solution {
public:
    Solution(int n_, const vector<vector<int>>& groups_): 
        n(n_), groups(groups_)
    {
        // pass
    }

    int query(int a, int b, int c) {
        int maxi = 0;
        stack<int> st;

        for (size_t p = 0, q = 0; /* pass */; /* pass */) {
            if (p < groups[a].size() && groups[a][p] <= maxi + 1) {
                maxi += groups[a][p];
                p++;
            } else if (c != 0) {
                while (q < groups[b].size() && groups[b][q] <= maxi + 1) {
                    st.push(groups[b][q]);
                    q++;
                }

                if (!st.empty() && st.top() <= maxi + 1) {
                    maxi += st.top();
                    st.pop();
                    c--;
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        return maxi;
    }
private:
    int n;
    const vector<vector<int> >& groups;
};

int main() {
    int n, T;
    vector<vector<int>> groups;

    n = readint();
    groups.resize(n);

    for (int i = 0; i < n; i++) {
        int m = readint();
        vector<int>& group = groups[i];
        group.resize(m);
        for (int j = 0; j < m; j++) {
            group[j] = readint();
        }
        sort(group.begin(), group.end());
    }

    Solution S(n, groups);

    T = readint();

    int a, b, c;
    while (T--) {
        a = readint();
        b = readint();
        c = readint();

        a--;
        b--;
        printf("%d\n", S.query(a, b, c));
    }

    return 0;
}
