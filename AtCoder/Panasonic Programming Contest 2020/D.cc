#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
std::string buffer;

void dfs(int cur) {
    if (cur == n) {
        puts(buffer.c_str());
        return;
    }

    set<char> st;
    for (int i = 0; i < cur; i++) {
        if (st.count(buffer[i])) {
            continue;
        }
        buffer.push_back(buffer[i]);
        dfs(cur + 1);
        buffer.pop_back();
        st.insert(buffer[i]);
    }

    char nxt = st.empty()? 'a': *st.rbegin() + 1;
    assert(nxt - 'a' == st.size());
    buffer.push_back(nxt);
    dfs(cur + 1);
    buffer.pop_back();
}

int main() {
    input(n);

    dfs(0);

    return 0;
}
