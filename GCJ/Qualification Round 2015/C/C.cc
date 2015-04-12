#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define error(x) cerr << x << endl

const int SIZE = 12345;

enum {
    ONE = 1,
    II  = 2,
    JJ  = 3,
    KK  = 4
};

int trans[5][5] = {
    {0, 0,   0,    0,   0},
    {0, ONE, II,   JJ,  KK},
    {0, II,  -ONE, KK, -JJ},
    {0, JJ,  -KK, -ONE, II},
    {0, KK,  JJ,  -II, -ONE}
};

int conv(char c) {
    switch (c) {
        case '1': return ONE;
        case 'i': return II;
        case 'j': return JJ;
        case 'k': return KK;
    }
    return -1;
}

struct Number {
    int sign;
    int value;

    Number() {}
    Number(char c) {
        sign = 1;
        value = conv(c);
    }
    Number(int isign, int ivalue): sign(isign), value(ivalue){}

    Number operator * (const Number& num) {
        int a = num.sign * sign;
        int b = trans[value][num.value];
        if (b < 0) {
            a *= -1;
            b = abs(b);
        }
        return Number{a, b};
    }
};

string _word;
string word;

long long L, X;

bool get_whole() {
    Number num('1');
    for (auto& c: _word) {
        num = num * Number(c);
    }
    Number ans('1');
    
    long long x = X;
    while (x) {
        if (x & 1) {
            ans = ans * num;
        }
        num = num * num;
        x >>= 1;
    }
    return ans.sign == -1 and ans.value == ONE;
}

int main() {
    int T, cas = 1;
    input(T);
    while (T--) {
        input(L >> X);
        input(_word);
        word = "";
        for (int i = 0; i < min(X, 19LL); i++) {
            word += _word;
        }
        
        Number num('1');
        
        bool ii = false;
        bool jj = false;
        bool kk = get_whole();
        
        int n = word.size();
        
        for (int i = 0; i < n - 1; i++) {
            num = num * word[i];
            
            if (num.sign == 1 && num.value == II) {
                ii = true;
            }else if (ii && num.sign == 1 && num.value == KK) {
                jj = true;
                break;
            }
        }
        kk = (kk && ii && jj);
        printf("Case #%d: ", cas++);
        puts(kk? "YES": "NO");
    }
    return 0;
}
