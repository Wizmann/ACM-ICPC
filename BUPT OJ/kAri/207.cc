//Result: 3459  207  通过 1178 ms 964 KB  GNU C++  1335 B 2014-03-18 21:38:05 test#wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 6;

string a, b, c;
set<pair<int, int> > st;
int num[N];

bool convert(const string& s, int& v)
{
    int len = s.size();
    v = 0;
    for (int i = 0; i < len; i++) {
        int u = num[s[i] - 'A'];
        if (i == 0 && u == 0) return false;
        v = v * 10 + u;
    }
    return true;
}


void dfs(int p)
{
    if (p == N) {
        int va, vb, vc;
        if (!convert(a, va)) return;
        if (!convert(b, vb)) return;
        if (!convert(c, vc)) return;

        if (va + vb == vc) {
            //printf("%d + %d == %d\n", va, vb, vc);
            st.insert(make_pair<int, int>(int(va), int(vb)));
        }
    } else {
        for (int i = 0; i < 10; i++) {
            num[p] = i;
            dfs(p + 1);
        }
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    input(T);

    while (T--) {
        st.clear();
        memset(num, 0, sizeof(num));
        input(a); input(b); input(c);
        dfs(0);
        print(st.size());
    }
    return 0;
}


