#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5;
const int INF = 1 << 29;

int n;
char instr[10];
int mp[256];

void init()
{
    const char _str[] = "12345RGBYW";
    for (int i = 0; _str[i]; i++) {
        mp[int(_str[i])] = i;
    }
}   

int conv(char x)
{
    return mp[int(x)];
}

int main()
{
    freopen("input.txt", "r", stdin);
    init();
    while (input(n)) {
        set<int> st;
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            scanf("%s", instr);
            int a = conv(instr[0]);
            int b = conv(instr[1]);
            int v = (1 << a) | (1 << b);
            // print(a << ' ' << b << ' ' << v);
            if (st.find(v) != st.end()) {
                continue;
            }
            st.insert(v);
            vec.push_back(v);
        }
        int ans = INF;
        for (int i = 0; i < (1 << 10); i++) {
            for (int j = 0; j < (int)vec.size(); j++) {
                for (int k = j + 1; k < (int)vec.size(); k++) {
                    int diff = vec[j] ^ vec[k];
                    if (!(i & diff)) {
                        goto fail;
                    }
                }
            }
            ans = min(ans, __builtin_popcount(i));
fail:       /*pass*/;
        }
        print(ans);
    }
    return 0;
}
