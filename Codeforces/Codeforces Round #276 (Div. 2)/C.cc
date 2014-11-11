#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x<< endl
#define input(x) cin >> x

typedef long long llint;

llint max_bit(llint a, llint b) {
    llint c = 1, maxi = 0;
    
    if (a == b) {
        return a;
    }
    
    while (true) {
        if (a <= c && c <= b) {
            maxi = c;
        }
        c = (c << 1) | 1;
        if (c > b) {
            break;
        }
    }
    
    if (maxi) {
        return maxi;
    } else {
        llint d = c ^ (c >> 1);
        return d | max_bit(a ^ d, b ^ d);
    }
}    

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    
    llint a, b;
    while (T--) {
        input(a >> b);
        print(max_bit(a, b));
    }
    return 0;
}
