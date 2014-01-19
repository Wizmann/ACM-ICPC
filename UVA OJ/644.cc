// Result: Wizmann  UVA 644 Accepted    0 KB    278 ms  C++ 4.5.3   1014 B  2014-01-10 18:34:39 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

vector<string> codecs;

inline void init()
{
    codecs.clear();
}

bool solve()
{
    sort(codecs.begin(), codecs.end());
    for (int i = 0; i + 1 < (int)codecs.size(); i++) {
        string& a = codecs[i];
        string& b = codecs[i + 1];
        //print(a <<' ' << b);
        if (b.compare(0, a.length(), a) == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T = 1;
    string tmp;
    init();
    while (input(tmp)) {
        if (tmp == "9") {
            if (solve()) {
                printf("Set %d is immediately decodable\n", T++);
            } else {
                printf("Set %d is not immediately decodable\n", T++);
            }
            init();
            continue;
        }

        codecs.push_back(tmp);
    }
    return 0;
}
