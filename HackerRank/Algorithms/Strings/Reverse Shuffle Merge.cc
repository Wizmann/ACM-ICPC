#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int ALPHA = 30;
const int SIZE = 123456;

int n;
char str[SIZE];
int cnt[ALPHA][SIZE];
int taken[ALPHA];
vector<int> pos[SIZE];
int ptr[ALPHA];

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%s", str);
    n = strlen(str);
    reverse(str, str + n);
    
    for (int i = 0; i < n; i++) {
        int c = str[i] - 'a';
        pos[c].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ALPHA; j++) {
            if (str[i] == 'a' + j) {
                cnt[j][i]++;
            }
            if (i - 1 >= 0) {
                cnt[j][i] += cnt[j][i - 1];
            }
        }
    }

    string res;

    int p = 0;
    for (int i = 0; i < n / 2; i++) {
        // print(p);
        for (int j = 0; j < ALPHA; j++) {
            if (ptr[j] >= pos[j].size()) {
                continue;
            }
            if (taken[j] * 2 >= cnt[j][n - 1]) {
                continue;
            }
            int pp = p;
            while (str[pp] != 'a' + j) {
                pp++;
            }
            if (pp > n) {
                continue;
            }
            bool flag = true;
            for (int k = 0; k < ALPHA; k++) {
                int l = taken[k];
                int r = cnt[k][n - 1] - cnt[k][pp];
                
                if (j == k) {
                    l++;
                }
                
                if (l * 2 <= cnt[k][n - 1] && l + r >= cnt[k][n - 1] / 2) {
                    continue;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                taken[j]++;
                ptr[j]++;
                res += 'a' + j;
                p = pp + 1;
                break;
            }
            if (j > 26) {
                print("fuck");
            }
        }
    }
    print(res);
    return 0;
}


