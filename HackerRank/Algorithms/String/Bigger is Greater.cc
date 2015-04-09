#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 128 + 19;

int n;
char word[SIZE];

int find_greater(char c, int p) {
    for (int i = n - 1; i >= p; i--) {
        if (word[i] > c) {
            return i;
        }
    }
    return -1;
}

bool do_next_permutation() {
    for (int i = n - 2; i >= 0; i--) {
        if (word[i] < word[i + 1]) {
            int p = find_greater(word[i], i + 1);
            swap(word[i], word[p]);
            reverse(word + i + 1, word + n);
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    input(T);
    while (T--) {
        input(word);
        n = strlen(word);
        if (do_next_permutation()) {
            print(word);
        } else {
            print("no answer");
        }
    }
    return 0;
}
