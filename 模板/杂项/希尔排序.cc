#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 12345;

template <typename T>
void shellsort(T array[], int n)
{
    int h = 1;
    while (h < n) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
                swap(array[j], array[j - h]);
            }
        }
        h /= 3;
    }
}

int A[SIZE];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    shellsort(A, n);
    printf("%d\n", A[n/2]);
    return 0;
}

