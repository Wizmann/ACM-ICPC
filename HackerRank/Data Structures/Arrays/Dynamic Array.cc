#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int n, q;
    int lastAns = 0;
    
    input(n >> q);
    
    vector<vector<int> > ns(n);
    
    int a, b, c;
    while (q--) {
        input(a >> b >> c);
        b = (b ^ lastAns) % n;
        if (a == 1) {
            ns[b].push_back(c);
        } else {
            c %= ns[b].size();
            printf("%d\n", lastAns = ns[b][c]);
        }
    }
    
    return 0;
}
