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

const int N = 123456;

char buffer[N];

string solve(string s, int k) {
    const int n = s.size();
    sort(s.begin(), s.end());

    string res;

    int ptr = 0;
    while (ptr < n) {
        int p = ptr;
        char mini = '~';
        char maxi = '\0';
        assert(mini > 'z' && maxi < 'a');
        for (int i = 0; i < k && ptr < n; i++) {
            mini = min(mini, s[ptr]);
            maxi = max(maxi, s[ptr]);
            ptr++;
        }
        // print(res);
        // print(mini << ' ' << maxi);

        if (!res.empty()) {
            if (mini == s.back()) {
                res += mini;
            } else {
                res += s.substr(p);
                break;
            }
        } else {
            if (mini == maxi) {
                res += mini;
            } else {
                res += maxi;
                break;
            }
        }
    }
    // print(res);
    return res;
}

string brute_force(string s, int k) {
    assert(k == 2);
    int n = s.size();
    string res = "~~~";
    sort(s.begin(), s.end());
    for (int i = 0; i < (1 << n); i++) {
        string left, right;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                left += s[j];
            } else {
                right += s[j];
            }
        }
        if (left.empty() || right.empty()) {
            continue;
        }
        res = min(res, max(left, right));
    }
    return res;
}

void test() {
    assert(solve("ccbbb", 2) == "bbcc");
    assert(solve("bbabc", 2) == "b");
    assert(solve("bababc", 2) == "abbbc");
    assert(solve("babab", 2) == "abb");
    assert(solve("baba", 2) == "ab");
    assert(solve("baacb", 2) == "abbc");
    assert(solve("baacb", 3) == "b");
    assert(solve("aaaaa", 3) == "aa");
    assert(solve("aaxxzz", 4) == "x");
    assert(solve("phoenix", 1) == "ehinopx");
    assert(solve("phoenix", 2) == "h");

    for (int i = 0; i < 100; i++) {
        int n = 10;
        string s;
        for (int j = 0; j < n; j++) {
            s += rand() % 5 + 'a';
        }
        // print(s);
        assert(brute_force(s, 2) == solve(s, 2));
    }
}

int main() {
    // test();

    int T;
    input(T);

    int n, k;
    while (T--) {
        scanf("%d%d", &n, &k);
        scanf("%s", buffer);

        puts(solve(buffer, k).c_str());
    }
    return 0;
}
