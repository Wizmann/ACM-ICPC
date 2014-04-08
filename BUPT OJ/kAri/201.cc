//Result: 3421  201  通过 14 ms   924 KB  GNU C++  445 B  2014-03-18 20:09:28 test#wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

#define SIZE 100100

int main()
{
    int T, v;
    input(T);
    while (T--) {
        input(v);
        print(abs(v));
    }
    return 0;
}

