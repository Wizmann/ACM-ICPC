#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class Solution {
public:
    Solution(const string& s_): s(s_) {
        // pass
    }

    string solve() {
        int n = s.size();
        set<pair<char, int> > pq;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            pq.insert({c, i});
        }

        int cur = 0;
        while (!pq.empty()) {
            auto p = *pq.begin();
            char c = p.first;
            int pos = p.second;

            assert (pos >= cur);

            while (!st.empty() && st.top() <= c) {
                res += st.top();
                st.pop();
            }

            while (cur <= pos) {
                st.push(s[cur]);
                pq.erase(pq.find({s[cur], cur}));
                cur++;
            }

            res += st.top();
            st.pop();
        }
        
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }

private:
    string s;
    stack<char> st;
    string res;
};

int main() {
    assert(Solution("cab").solve() == "abc");
    assert(Solution("acdb").solve() == "abdc");
    assert(Solution("cadcab").solve() == "aabcdc");


    string s; 
    input(s);
    Solution sol(s);
    print(sol.solve());
    return 0;
}
