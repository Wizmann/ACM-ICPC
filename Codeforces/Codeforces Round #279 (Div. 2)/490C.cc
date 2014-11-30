#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1234567;

string num;
int a, b;
int ma[SIZE], mb[SIZE];


void show_ans(const string& num, int la, int lb) {
    print(num.substr(0, la));
    print(num.substr(la, lb));
}

int main() {
    freopen("input.txt", "r", stdin);
    while (input(num)) {
        int n = num.length();
        input(a >> b);
        
        for (int i = 0, u = 0; i < n; i++) {
            char c = num[i];
            u = (u * 10 + (c - '0')) % a;
            ma[i] = u;
        }
        
        for (int i = n - 1, u = 0, ten = 1; i >= 0; i--) {
            char c = num[i];
            u = (u + ten * (c - '0')) % b;
            ten = (ten * 10) %b ;
            mb[i] = u;
        }

        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (num[i + 1] == '0') {
                continue;
            }
            int mod_a = ma[i];
            int mod_b = mb[i + 1];

            if (!mod_a && !mod_b) {
                print("YES");
                flag = true;
                show_ans(num, i + 1, n - i - 1);
                break;
            }
        }
        if (!flag) {
            print("NO");
        }
    }
    return 0;
}
