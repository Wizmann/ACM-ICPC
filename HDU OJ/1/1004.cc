#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
map<string, int> mp;

int main() {
    string s;
    while (input(n) && n) {
        mp.clear();
        for (int i = 0; i < n; i++) {
            input(s);
            mp[s]++;
        }

        int maxi = 0;
        for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
            if (iter->second > maxi) {
                maxi = iter->second;
                s = iter->first;
            }
        }
        print(s);
    }
    return 0;
}
