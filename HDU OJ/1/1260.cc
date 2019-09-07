#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

std::string add_time(int t) {
    const int DAY = 24 * 60 * 60;
    t %= DAY;

    int h = 8;
    int m = 0;
    int s = t;

    if (s >= 60) {
        m += s / 60;
        s %= 60;
    }
    if (m >= 60) {
        h += m / 60;
        m %= 60;
    }
    h %= 24;

    string suffix;

    if (h == 0) {
        suffix = "pm";
    } else if (h < 12) {
        suffix = "am";
    } else if (h >= 12) {
        suffix = "am";
    } else {
        assert(false);
    }

    char buffer[123];
    sprintf(buffer, "%02d:%02d:%02d %s", h, m, s, suffix.c_str());
    return buffer;
}

int main() {
    int T;
    input(T);
    while (T--) {
        int n;
        input(n);

        vector<int> ns1(n);
        vector<int> ns2(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns1[i]);
        }

        for (int i = 1; i < n; i++) {
            scanf("%d", &ns2[i]);
        }

        int a = 0;
        int b = ns1[0];

        for (int i = 1; i < n; i++) {
            int bb = min(a + ns2[i], b + ns1[i]);
            a = b;
            b = bb;
        }

        string t = add_time(b);
        puts(t.c_str());
    }
    return 0;
}
