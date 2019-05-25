#include <cstdio>
#include <iostream>

using namespace std;

#define input(x) cin >> x
#define print(x) cout << x << endl

int main() {
    int T;
    input(T);

    int case_ = 0;
    while (T--) {
        int n, m, k;
        double p;
        input(n >> m >> k >> p);
        printf("Case %d: %lf\n", ++case_, n * k * p);
    }
    return 0;
}
