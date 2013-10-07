//Result:wizmann	2273	Accepted	712K	32MS	G++	1094B	2013-10-07 12:14:02
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5120;

void parse(const char str[], int& r, int& c)
{
    r = c = 0;
    int i = 1;
    for (/*pass*/; str[i] != 'C'; i++) {
        r *= 10;
        r += str[i] - '0';
    }

    i++;

    for (/*pass*/; str[i]; i++) {
        c *= 10;
        c += str[i] - '0';
    }
}

string to_AZ(int x)
{
    string res;
    while (x) {
        int t = x % 26;
        x /= 26;
        if (t == 0) {
            res = string("Z") + res;
            x--;
        } else {
            res = string() + char('A' + t - 1) + res;
        }
    }
    return res;
}

int main()
{
    string instr;
    while(input(instr)) {
        int r, c;
        parse(instr.c_str(), r, c);

        if (r == 0 && c == 0) break;

        string strc = to_AZ(c);
        printf("%s%d\n", strc.c_str(), r);
    }
    return 0;
}
