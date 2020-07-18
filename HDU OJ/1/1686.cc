#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

vector<int> kmp_next(const string& s) {
    int n = s.size();
    vector<int> next(n + 1, -1);
    for (int pre = -1, suf = 0; pre < n && suf < n; /* pass */) {
        if (pre == -1 || s[pre] == s[suf]) {
            pre++;
            suf++;
            next[suf] = pre;
        } else {
            pre = next[pre];
        }
    }
    return next;
}

int kmp_match(const string& w, const string& t) {
    auto next = kmp_next(w);
    int n = t.size();
    int m = w.size();
    int cnt = 0;

    // print(w << ' ' << t);

    for (int i = 0, j = 0; i < n && j < m; /* pass */) {
        if (j == -1 || t[i] == w[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
        if (j == m) {
            cnt++;
            j = next[j];
        }
    }
    return cnt;
}

char buffer[1234567];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%s", buffer);
        string a(buffer);
        scanf("%s", buffer);
        string b(buffer);

        printf("%d\n", kmp_match(a, b));
    }

    return 0;
}
