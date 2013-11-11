//Result: Wizmann   UVA 10878   Accepted    0 KB    16 ms   C++ 4.5.3   866 B   2013-10-29 22:23:36
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

const int LINE_SIZE = 1024;

char* getline(char* line)
{
    char * res = NULL;
    while (1) {
        res = fgets(line, LINE_SIZE, stdin);
        if (!res) break;
        if (*line != '\0' && *line != '\n') break;
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    char line[LINE_SIZE];
    while (getline(line)) {
        // print(line);
        if (*line == '_') continue;
        char c = 0;
        int p = 0;
        for (int i = strlen(line); i >= 0; i--) {
            if (line[i] == ' ' || line[i] == 'o') {
                c |= (line[i] == 'o'? 1 : 0) << p;
                p++;
            }
        }
        putchar(c);
    }
    return 0;
}
