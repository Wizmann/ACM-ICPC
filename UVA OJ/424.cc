// Result: Wizmann  UVA 424 Accepted    0 KB    16 ms   C++ 4.5.3   1000 B  
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t STR_SIZE = 1024;

char a[STR_SIZE], b[STR_SIZE];


void parse()
{
    int len = strlen(b);
    for (int i = 0; i < (int)STR_SIZE; i++) {
        if (i < len) b[i] -= '0';
        else b[i] = 0;
    }
    reverse(b, b + len);
}

void xplus()
{
    parse();
    int g = 0;
    for (int i = 0; i < (int)STR_SIZE; i++) {
        int x = a[i] + b[i] + g;
        g = x / 10;
        x %= 10;
        a[i] = x;
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    while (1) {
        scanf("%s", b);
        if (strcmp(b, "0") == 0) break;
        xplus();
    }

    int ptr = STR_SIZE - 1;
    while (!a[ptr]) {
        ptr--;
    }

    while (1) {
        putchar('0' + a[ptr]);
        if (!ptr) break;
        ptr--;
    }
    puts("");

    return 0;
}

