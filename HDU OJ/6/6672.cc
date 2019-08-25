#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

vector<llint> res = {
    -1, 1, 1, 0, 3, 0, 3, 5, 4
};

llint scannum() {
    char buffer[100];
    scanf("%s", buffer);
    llint res = 0;
    for (int i = 0; buffer[i]; i++) {
        res = res * 10 + buffer[i] - '0';
    }
    return res;
}

void printnum(llint u) {
    vector<int> v;
    if (u == 0) {
        v.push_back(0);
    }
    while (u) {
        v.push_back(u % 10);
        u /= 10;
    }
    reverse(v.begin(), v.end());
    for (auto num: v) {
        putchar('0' + num);
    }
    puts("");
}


int main() {
    int T;
    input(T);
    while (T--) {
        llint n = scannum();

        if (n < res.size()) {
            printnum(res[n]);
        } else if ((n - 9) % 6 == 0 || (n - 9) % 6 == 2) {
            printnum((n - 9) / 6 + 1);
        } else if ((n - 9) % 6 == 1) {
            printnum(n - 1);
        } else if (n % 2 == 0) {
            printnum(n / 2);
        } else {
            llint delta = (n - 13) / 6;
            printnum(9 + 4LL * delta);
        }
    }
    return 0;
}
