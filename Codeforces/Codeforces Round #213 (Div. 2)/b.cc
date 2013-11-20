#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 100100;

int n;
int A[SIZE];

int judge(int &t)
{
    int st = t - 1 >= 0? t - 1: t;
    int res = 0;
    for (int i = 0; st + i < n; i++) {
        if (i >= 2 && 
                A[st + i - 1] + A[st + i - 2] == A[st + i]) {
            res = i + 1;
        } else if (i < 2) {
            res++;
            continue;
        } else {
            break;
        }
    }
    t = st + res;
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    while(input(n)) {
        for (int i = 0; i < n; i++) {
            input(A[i]);
        }
        int ans = 0;
        int t = 0;
        while (t < n) {
            int res = judge(t);
            //print(t);
            ans = max(ans, res);
        }

        print(ans);
    }
    return 0;
}

