#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;

int X[SIZE], Y[SIZE], Z[SIZE];
char str[SIZE];
int m;

bool case_one(int x, int y, int z, int len)
{
    // start with z, y
    z--; y--;
    len -= 2;

    x -= len / 3;
    y -= len / 3;
    z -= len / 3;

    if (len % 3 == 1) {
        x--;
    } else if (len % 3 == 2) {
        x--; z--;
    }

    return !x && !y && !z;
}

bool case_two(int x, int y, int z ,int len)
{
    // start with x, z
    x--; z--;
    len -= 2;

    x -= len/3;
    y -= len/3;
    z -= len/3;

    if (len % 3 == 1) {
        y--;
    } else if (len % 3 == 2) {
        y--; x--;
    }

    return !x && !y && !z;
}

bool case_thr(int x, int y, int z, int len)
{
    //start with y, x;
    y--; x--;
    len -= 2;

    x -= len/3;
    y -= len/3;
    z -= len/3;

    if (len % 3 == 1) {
        z--;
    } else if (len % 3 == 2) {
        z--; y--;
    }

    return !x && !y && !z;
}

void init()
{
    memset(X, 0, sizeof(X));
    memset(Y, 0, sizeof(Y));
    memset(Z, 0, sizeof(Z));
}

void _calc(int* A, char x)
{
    int g = 0;
    for (int i = 1; str[i]; i++) {
        if (str[i] == x) {
            g++;
        }
        
        A[i] = g;
    }
}

void calc()
{
    _calc(X, 'x');
    _calc(Y, 'y');
    _calc(Z, 'z');
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    init();
    input((str + 1));
    calc();
    
    input(m);
    while (m--) {
        input(a >> b);
        int x = X[b] - X[a-1];
        int y = Y[b] - Y[a-1];
        int z = Z[b] - Z[a-1];

        int len = b - a + 1;

        if (len < 3) print("YES");
        else if (!x || !y || !z) print("NO");
        else {
            if (case_one(x, y, z, len) ||
                case_two(x, y, z, len) ||
                case_thr(x, y, z, len)) {
                print("YES");
            } else {
                print ("NO");
            }
        }
    }
    return 0;
}


