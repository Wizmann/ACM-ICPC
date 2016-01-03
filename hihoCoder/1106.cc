#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint ;

const llint MAXI = 1000000000LL;

vector<llint> vier;

void init() {
    llint v = 1;
    while (v <= MAXI) {
        vier.push_back(v);
        v *= 4;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    init();
    
    int T, a, b;
    input(T);
    while (T--) {
        scanf("%d%d", &a, &b);
        a--;
        if (b < vier.size()) {
            llint v = vier[b];
            a %= v;
        }
        
        while (a && a % 4 != 1 && a % 4 != 2) {
            b--;
            a /= 4;
        }
        if (a == 0) {
            b = 0;
        }
        printf("%d\n", b);
    }
    return 0;
}
