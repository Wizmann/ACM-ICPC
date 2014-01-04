#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 500010;

int n;
int A[SIZE];

bool judge(int x)
{
    int i, j;
    for (i = x - 1, j = n - 1; i >= 0 && j >= x; i--, j--) {
        if (A[i] * 2 <= A[j]) {
            continue;
        } else {
            return false;
        }
    }
    return i == -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    input(n);
    for (int i = 0; i < n; i++) {
        input(A[i]);
    }
    sort(A, A + n);

    int now = 0;
    int step = n;
    while (step) {
        int half = step >> 1;
        int mid = now + half;
        //print(mid << ' ' << judge(mid));
        if (!judge(mid)) {
            step = half;
        } else {
            now = mid + 1;
            step = step - half - 1;
        }
    }

    print(n - now + 1);

    return 0;
}
