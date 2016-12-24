#include <cstdio>
#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111111;

int main() {
    int n, x;
    vector<int> digits(SIZE, 0);
    
    input(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        digits[x]++;
    }
    
    int g = 0;
    for (int i = 0; i < SIZE; i++) {
        digits[i] += g;
        g = digits[i] / 2;
        digits[i] &= 1;
    }
    
    print(accumulate(digits.begin(), digits.end(), 0));
    return 0;
}
