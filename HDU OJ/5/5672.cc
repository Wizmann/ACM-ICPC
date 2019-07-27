#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 11111111;

char buffer[SIZE];

llint solve(const string& s, int k) {
    const int n = s.size();

    int p = 0;
    int q = 0;

    map<char, int> mp;
    llint res = 0;
    int cnt = 0;

    while (p < n) {
        while (q < n && cnt < k) {
            char c = s[q];
            if (mp[c] == 0) {
                cnt++;
            }
            mp[c]++;
            q++;
        }

        // print(p << ' ' << q);
        if (cnt == k) {
            res += n - q + 1;
        }

        char c = s[p];
        mp[c]--;
        if (mp[c] == 0) {
            cnt--;
        }
        p++;
    }
    return res;
}

int main() {
    int T;
    input(T);
    while (T--) {
        int k;

        scanf("%s", buffer);
        scanf("%d", &k);

        string s(buffer);

        print(solve(s, k));
    }
    return 0;
}
