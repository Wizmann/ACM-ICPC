// Result: Nov 25, 2013 9:00:54 AM  Wizmann  B - Dima and To-do List     GNU C++    Accepted    62 ms   400 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t SIZE = 100100;
const int INF = 1 << 29;

int n, k;
int A[SIZE];

int main()
{
    freopen("input.txt", "r", stdin);
    input(n >> k);
    for (int i = 0; i < n; i++) {
        input(A[i]);
    }

    int res = -1, mini = INF;
    for (int i = 0; i < k; i++) {
        int sum = 0;
        for (int j = i; j < n; j += k) {
            sum += A[j];
        }
        if (sum < mini) {
            mini = sum;
            res = i + 1;
        }
    }
    //print(mini);
    print(res);
    return 0;
}
