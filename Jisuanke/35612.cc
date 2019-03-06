#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int a, b, c;
    input(a >> b >> c);
    int cnt = 0;
    
    cnt += a;
    b = a * b;
    
    cnt += b;
    c = b * c;
    
    cnt += c;
    
    print(cnt);
    return 0;    
}
