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
    int T;
    input(T);
    while (T--) {
        scanf("%s", buffer);
        string s = buffer;
        int n = s.size();
        auto next = kmp_next(s);
        /*
        for (int i = 0; i <= n; i++) {
            printf("%d ", next[i]);
        }
        puts("");
        */
        int loop = n - next[n];
        if (n != loop && n % loop == 0) {
            puts("0");
        } else {
            printf("%d\n", loop - n % loop);
        }
    }

    return 0;
}
