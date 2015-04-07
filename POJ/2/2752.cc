#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 412345;

int n;
int next[SIZE];
char name[SIZE];
vector<int> ans;

void get_next() {
    for (int pre = -1, suf = 0;
            suf < n; /* pass */) {
        if (pre == -1 || name[pre] == name[suf]) {
            pre++; suf++;
            next[suf] = pre;
        } else {
            pre = next[pre];
        }
    }
}

void get_ans() {
    int p = n;
    while (next[p]) {
        ans.push_back(next[p]);
        p = next[p];
    }
    reverse(ans.begin(), ans.end());
    ans.push_back(n);
}

int main() {
    while (scanf("%s", name) != EOF) {
        n = strlen(name);
        memset(next, -1, sizeof(next));
        ans.clear();
        get_next();
        get_ans();
        for (int i = 0; i < (int)ans.size(); i++) {
            if (i) {
                printf(" ");
            }
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
