#include <cstdio>
#include <iostream>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
typedef long long llint;
 
int main() {
    llint res = 0;
     
    int n;
    input(n);
     
    int cur = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cur);
        if (cur < 0) {
            res += 1LL * (i + 1) * cur;
        } else {
            res += cur;
        }
    }
    print(res);
    return 0;
}
