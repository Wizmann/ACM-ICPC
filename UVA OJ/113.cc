#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main()
{
    double x, n;
    while(input(n >> x)) {
        printf("%.0f\n", exp(log(x)/n));
    }
    return 0;
}

