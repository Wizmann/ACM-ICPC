#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;

int a[SIZE], b[SIZE], c[SIZE];
vector<int> v;
int maxA[SIZE], maxB[SIZE];
int n, d;
llint x;

//x is 64-bit variable;
llint getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int brute_force(int u)
{
    int ans = 0;
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        int i = *iter;
        if (i > u) {
            break;
        }
        ans = max(ans, a[u - i]);
    }
    return ans;
}


int main()
{
    freopen("input.txt", "r", stdin);
    input(n >> d >> x);
    initAB();
    /*
    for (int i = 0; i < n; i++) {
        print(brute_force(i));
    }
    */

    for (int i = 0; i < n; i++) {
        c[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (b[i]) {
            v.push_back(i);
        }
    }

    int S = min(19, n);
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = n; j >= 1 && n - j <= S; j--) {
            int x = i - c[j];
            if (c[j] <= i && b[x]) {
                s = j;
                break;
            }
        }
        if (!s) {
            s = brute_force(i);
        }
        printf("%d\n", s);
    }
    return 0;
}
