#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int T;
    input(T);
    while (T--) {
        string s;
        input(s);
        int n = s.size();
        bool flag = true;
        for (int i = 1, j = n - 2; i < n && j >= 0; i++, j--) {
            int a = abs(s[i] - s[i - 1]);
            int b = abs(s[j] - s[j + 1]);
            if (a != b) {
                flag = false;
                break;
            }
        }
        if (flag) {
            puts("Funny");
        } else {
            puts("Not Funny");
        }
    }
    return 0;
}
