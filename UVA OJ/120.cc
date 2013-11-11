// Result: Wizmann  UVA 120 Accepted    0 KB    22 ms   C++ 4.5.3   1605 B  
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t SIZE = 128;
const int INF = 1 << 28;

int n;
int num[SIZE];
vector<int> ans;
char buffer[SIZE * 4];

bool readline()
{
    char *s = fgets(buffer, SIZE * 4, stdin);
    if (!s) return false;

    n = 0;
    int t = -1;
    for (int i = 0; /*PASS*/; i++) {
        if (isdigit(s[i])) {
            if (t == -1) t = 0;
            t = t * 10 + s[i] - '0';
        } else if (t != -1){
            num[n++] = t;
            t = -1;
        }
        
        if (!s[i]) break;
    }
    if (!n) return false;
    return true;
}

void do_sort()
{
    for (int i = n - 1; i >= 0; i--) {
        int maxi = -INF, pos = -1;
        for (int j = 0; j <= i; j++) {
            if (num[j] >= maxi) {
                maxi = num[j];
                pos = j;
            }
        }
        if (pos == i) continue;
        
        if (pos != 0) {
            reverse(num, num + pos + 1);
            ans.push_back(n - pos);
        }
        reverse(num, num + i + 1);
        ans.push_back(n - i);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    ans.reserve(SIZE * 2);
    while(readline()) {
        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", num[i]);
        }
        puts("");
        ans.clear();
        do_sort();
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%d ", ans[i]);
        }
        printf("0\n");
    }
    return 0;
}
