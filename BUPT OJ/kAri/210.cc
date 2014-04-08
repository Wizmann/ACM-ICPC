//Result: 3419  210  通过 8 ms    904 KB  GNU C++  692 B  2014-03-18 20:05:37 test#wizmann
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

const int N = 4;
const int rists[N] = {31, 15, 7, 3};

bool judge(int v)
{
    for (int i = 0; i < 4; i++) {
        if (v % rists[i] == 0) {
            v /= rists[i];
        }
    }
    return v == 1;
}


int main()
{
    int T, v;
    input(T);
    while (T--) {
        scanf("%d", &v);
        puts(judge(v)? "True": "False");
    }
    return 0;
}

