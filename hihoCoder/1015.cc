#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

string needle;
string haystack;
vector<int> kmp_next;

void get_kmp_next() {
    int n = needle.size();
    kmp_next.resize(n + 1);
    kmp_next[0] = -1;
    
    for (int pre = -1, suf = 0; suf < n; /* pass */) {
        if (pre == -1 || needle[pre] == needle[suf]) {
            pre++;
            suf++;
            kmp_next[suf] = pre;
        } else {
            pre = kmp_next[pre];
        }
    }
}

int kmp_search() {
    int ans = 0;
    int n = needle.size();
    int m = haystack.size();
    for (int i = 0, j = 0; i < m; /* pass */) {
        if (j == -1 || needle[j] == haystack[i]) {
            i++;
            j++;
            
            if (j == n) {
                ans++;
                j = kmp_next[j];
            }
        } else {
            j = kmp_next[j];
        }
    }
    return ans;
}

int main() {
    int T;
    input(T);
    
    while (T--) {
        input(needle);
        input(haystack);
        get_kmp_next();
        print(kmp_search());
    }
    return 0;
}
