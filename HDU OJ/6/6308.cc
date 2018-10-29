#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int to_int(const string& s) {
    int res = 0;
    const int n = s.size();
    for (int i = 0; i < n; i++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

string solve(int h, int m, string offset) {
    int g = offset[3] == '-'? -1: +1;

    int dh = 0;
    int dm = 0;

    if (offset.find('.') != string::npos) {
        dm = g * (offset[offset.size() - 1] - '0');
        assert(offset[offset.size() - 2] == '.');
        string t = offset.substr(4);
        t.pop_back();
        t.pop_back();
        dh = g * to_int(t);
    } else {
        string t = offset.substr(4);
        dh = g * to_int(t);
    }

    dh -= 8;

    h += dh;
    m += dm * 6;

    while (m < 0) {
        h -= 1;
        m += 60;
    } 

    while (m >= 60) {
        h += 1;
        m %= 60;
    }

    while (h < 0) {
        h += 24;
    }
    h %= 24;

    assert(0 <= h <= 23);
    assert(0 <= m <= 59);
    char temp[100];
    snprintf(temp, 100, "%02d:%02d", h, m);
    return string(temp);
}

int main() {
    int T;

    assert(solve(22, 22, "UTC-8.5") == "05:52");
    assert(solve(13, 50, "UTC+10.5") == "16:20");
    assert(solve(13, 22, "UTC+14") == "19:22");
    assert(solve(13, 22, "UTC-12") == "17:22");
    assert(solve(13, 22, "UTC-8") == "21:22");
    assert(solve(11, 11, "UTC+8") == "11:11");
    assert(solve(11, 11, "UTC+8.5") == "11:41");
    assert(solve(11, 11, "UTC+8.1") == "11:17");
    assert(solve(11, 12, "UTC+9") == "12:12");
    assert(solve(11, 23, "UTC+0") == "03:23");

    input(T);

    while (T--) {
        int h, m;
        char offset[100];

        scanf("%d%d%s", &h, &m, offset);

        puts(solve(h, m, string(offset)).c_str());
    }
    return 0;
}
