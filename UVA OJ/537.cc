// Result:12574992  537 Artificial Intelligence?    Accepted    C++ 0.015   2013-10-28 03:02:32
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Value
{
    double v;
    bool exist;

    inline void init()
    {
        v = 0;
        exist = false;
    }

    inline void set(double iv)
    {
        v = iv;
        exist = true;
    }
};

Value P, U, I;

void getline(char *s, int n)
{
    *s = '\0';
    while (!*s || *s == '\n') {
        fgets(s, n, stdin);
    }
}

void parse(char *s, int pos)
{
    char X = s[pos - 1];
    pos++;
    double v = 0;
    string str_v = "";
    while ((s[pos] >= '0' && s[pos] <= '9') || s[pos] == '.') {
        str_v += s[pos];
        pos++;
    }
    v = atof(str_v.c_str());
    if (s[pos] == 'M') v *= 1000 * 1000;
    else if (s[pos] == 'm') v /= 1000;
    else if (s[pos] == 'k') v *= 1000;
    

    switch (X) {
        case 'U': U.set(v); break; 
        case 'P': P.set(v); break;
        case 'I': I.set(v); break;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    const int STR_SIZE = 10240;
    int T;
    char s[STR_SIZE];
    input(T);
    int cas = 1;
    while (T--) {
        P.init();
        U.init();
        I.init();

        getline(s, STR_SIZE);
        for (int i = 0; s[i]; i++) {
            if (s[i] == '=') {
                parse(s, i);
            }
        }
        
        printf("Problem #%d\n", cas++);
        if (!P.exist) {
            double ans = I.v * U.v;
            printf("P=%.2lfW\n", ans);
        } else if (!U.exist) {
            double ans = P.v / I.v;
            printf("U=%.2lfV\n", ans);
        } else if (!I.exist) {
            double ans = P.v / U.v;
            printf("I=%.2lfA\n", ans);
        } else {
            // pass
        }
        puts("");
    }
    return 0;
}

