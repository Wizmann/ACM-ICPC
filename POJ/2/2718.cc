#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint INF = 0x3f3f3f3f3f3f3f3fLL;

llint myabs(llint x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

llint check(const vector<char>& ns) {
    int n = ns.size();
    llint l = 0;
    llint r = 0;
    
    if (ns[0] == 0 || ns[n / 2] == 0) {
        return INF;
    }
    
    for (int i = 0; i < n / 2; i++) {
        l = l * 10 + ns[i];
    }
    
    for (int i = n / 2; i < n; i++) {
        r = r * 10 + ns[i];
    }
    
    return myabs(l - r);
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    string line;
    input(T);
    getchar();
    while (T--) {
        vector<char> ns;
        getline(cin, line);

        int l = line.size();
        for (int i = 0; i < l; i++) {
            if ('0' <= line[i] && line[i] <= '9') {
                ns.push_back(line[i] - '0');
            }
        }

        int n = ns.size();
        llint ans = INF;
        
        if (ns[0] == 0) {
            ans = 0;
            for (int i = 1; i < n; i++) {
                ans = ans * 10 + ns[i];
            }
        }
        swap(ns[0], ns[1]);
        
        do {
            ans = min(ans, check(ns));
        } while (next_permutation(ns.begin(), ns.end()));
        print(ans);
    }
    return 0;
}
