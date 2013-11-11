//Result: Wizmann   UVA 10361   Accepted    0 KB    16 ms   C++ 4.5.3
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

const size_t STR_SIZE = 1024;

char line[STR_SIZE];

void split(const char * ss, vector<string>& s)
{
    int ptr = 0;
    s.clear();
    s.push_back("");
    while (*ss && *ss != '\n') {
        if (*ss != '<' && *ss != '>') {
            s[ptr] += *ss;
        } else {
            ptr++;
            s.push_back("");
        }
        ss++;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    while (T--) {
        *line = '\0';
        while (!*line || *line=='\n') fgets(line, STR_SIZE, stdin);
        vector<string> a;
        split(line, a);
        *line = '\0';
        while (!*line || *line=='\n') fgets(line, STR_SIZE, stdin);
        //print(line);
        int t = strlen(line) - 1;
        while (line[t] == '.' || line[t] == '\n') t--;
        line[t+1] = '\0';

        print(a[0] + a[1] + a[2] + a[3] + a[4]);
        print(string(line) + a[3] + a[2] + a[1] + a[4]);
    }
    return 0;
}


