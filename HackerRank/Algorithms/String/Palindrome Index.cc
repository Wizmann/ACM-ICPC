#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

bool check(const string& s, int idx) {
    int l = 0;
    int r = s.length() - 1;
    
    while (l < r) {
        if (l == idx) {
            l++;
            continue;
        }
        if (r == idx) {
            r--;
            continue;
        }
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    int T;
    input(T);
    
    while (T--) {
        string s;
        input(s);
        int l = 0;
        int r = s.length() - 1;

        int res = -1;

        while (l < r) {
            if (s[l] != s[r]) {
                if (check(s, l)) {
                    res = l;
                    break;
                } 
                if (check(s, r)) {
                    res = r;
                    break;
                }
            }
            l++;
            r--;
        }

        print(res);
    }
    
    return 0;
}
