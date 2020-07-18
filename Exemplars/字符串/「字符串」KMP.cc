// HDU2087
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
    vector<int> next = kmp_next(t);
    int n = w.size();
    int m = t.size();
    int cnt = 0;
    for (int i = 0, j = 0; i < n && j < m; /* pass */) {
        if (j == -1 || w[i] == t[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
        if (j == m) {
            j = 0;
            cnt++;
        }
    }
    return cnt;
}

char buffer[1234];

int main() {
    while (true) {
        scanf("%s", buffer);
        string a(buffer);
        if (a == "#") {
            break;
        }
        scanf("%s", buffer);
        string b(buffer);

        printf("%d\n", kmp_match(a, b));
    }

    return 0;
}
