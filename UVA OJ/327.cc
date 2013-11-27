// Result: 327  Evaluating Simple C Expressions Accepted    C++ 0.056   2013-11-13 06:09:26
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t SIZE = 1024;
const size_t ALPHA = 32;

char buffer[SIZE];
char calc[SIZE];
int A[ALPHA], B[ALPHA];
char exist[ALPHA];
int ptr;

void init()
{
    for (int i = 1; i <= 26; i++) {
        A[i - 1] = B[i - 1] = i;
    }
    memset(exist, 0, sizeof(exist));
    ptr = 0;
}

void strip()
{
    for (int i = 0; buffer[i]; i++) {
        if (isalpha(buffer[i]) || buffer[i] == '+' 
                    || buffer[i] == '-') {
            calc[ptr++] = buffer[i];
            exist[buffer[i] - 'a'] = 1;
        }
    }
    calc[ptr] = '\0';
    buffer[strlen(buffer) - 1] = '\0';
}

void preopt()
{
    int p = 0;
    char temp[SIZE];
    for (int i = 0; calc[i]; i++) {
        if ((calc[i] == '+' || calc[i] == '-') &&
            calc[i + 1] == calc[i] && isalpha(calc[i+2])) {
                char t = calc[i + 2];
                if (calc[i] == '+') {
                    A[t - 'a']++;
                    B[t - 'a']++;
                } else {
                    A[t - 'a']--;
                    B[t - 'a']--;
                }
                i++;
        } else {
            temp[p++] = calc[i];
        }
    }
    temp[p] = '\0';
    strcpy(calc, temp);
}

void aftopt()
{
    int p = 0;
    char temp[SIZE];
    char v = '\0';
    for (int i = 0; calc[i]; i++) {
        if ((calc[i] == '+' || calc[i] == '-') &&
                calc[i] == calc[i + 1] &&
                v) {
            if (calc[i] == '+') {
                B[v - 'a']++;
            } else {
                B[v - 'a']--;
            }
            i++;
            v = '\0';
        } else {
            temp[p++] = calc[i];
            if (isalpha(calc[i])) {
                v = calc[i];
            }
        }
    }
    temp[p] = '\0';
    strcpy(calc, temp);
}

void parse()
{
    preopt();
    aftopt();
}

int solve()
{
    int g = 1;
    int ans = 0;
    for (int i = 0; calc[i]; i++) {
        if (isalpha(calc[i])) {
            int v = A[calc[i] - 'a'];
            ans += g * v;
        } else {
            if (calc[i] == '-') g = -1;
            else g = 1;
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    while (1) {
        if (!fgets(buffer, SIZE, stdin)) break;
        init();
        strip();
        printf("Expression: %s\n", buffer);
        parse();
        printf("    value = %d\n", solve());
        for (int i = 0; i < (int)ALPHA; i++) {
            if (exist[i]) {
                printf("    %c = %d\n", i + 'a', B[i]);
            }
        }
    }
    return 0;
}

