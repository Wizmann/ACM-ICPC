#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

string word;

int solve() {
    int A = 0;
    int B = 0;
    bool first = true;
    
    for (auto c: word) {
        if (c == 'A') {
            A += first? 0: 1;
            A = min(A, B);
            
            B = A + 1;
        } else {
            B += first? 0: 1;
            B = min(A, B);
            
            A = B + 1;
        }
        
        first = false;
    }
    return min(A, B);
}

int main() {
    int T;
    input(T);
    while (T--) {
        input(word); 
        print(solve());
    }
    return 0;
}
