#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

vector<int> kmp_next(const vector<int>& ns) {
    int n = ns.size();
    vector<int> kmpnext(n + 1, -1);

    for (int prefix = -1, suffix = 0; prefix < n && suffix < n; /* pass */) {
        if (prefix == -1 || ns[prefix] == ns[suffix]) {
            prefix++;
            suffix++;
            kmpnext[suffix] = prefix;
        } else {
            prefix = kmpnext[prefix];
        }
    }
    return kmpnext;
}

int kmp_match(const vector<int>& ns, const vector<int>& ms) {
    auto kmpnext = kmp_next(ms);
    int n = ns.size();
    int m = ms.size();

    for (int i = 0; i < m + 1; i++) {
        printf("%d ", kmpnext[i]);
    }
    puts("");

    for (int i = 0, j = 0; i < n && j < n; /* pass */) {
        if (j == -1 || ns[i] == ms[j]) {
            i++;
            j++;
        } else {
            j = kmpnext[j];
        }
        if (j == m) {
            return i - m + 1;
        }
    }
    return -1;
}

int main() {
    int T;
    input(T);

    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        vector<int> ms(m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &ms[i]);
        }
        printf("%d\n", kmp_match(ns, ms));
    }

    return 0;
}
