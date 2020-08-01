#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
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

char buffer[123456];

int main() {
    while (scanf("%s", buffer) != EOF) {
        string s = buffer;
        s += '#';
        scanf("%s", buffer);
        s += buffer;
        int n = s.size();
        auto next = kmp_next(s);
        int u = next[n];
        if (u) {
            printf("%.*s ", u, s.c_str());
        }
        printf("%d\n", next[n]);
    }

    return 0;
}
