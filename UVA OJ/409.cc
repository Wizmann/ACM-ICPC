// Result: Wizmann  UVA 409 Accepted    0 KB    15 ms   C++ 4.5.3   1808 B  2013-10-28 16:11:14
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t STR_SIZE = 1024;
const int INF = 1LL << 28;

int n, m;
set<string> exc;

int judge(const string& words) {
    int r = 0;
    string t = "";
    for (int i = 0; i <= (int)words.size(); i++) {
        if (words[i] >= 'a' && words[i] <= 'z') {
            t += words[i];
        } else if (words[i] >= 'A' && words[i] <= 'Z') {
            t += words[i] - 'A' + 'a';
        } else {
            if (exc.find(t) != exc.end()) {
                r++;
            }
            t = "";
        }
    }
    return r;
}

int main()
{
    freopen("input.txt", "r", stdin);
    string word;
    vector<string> ans_str;
    int ans;
    int cas = 1;
    while (input(n >> m)) {
        printf("Excuse Set #%d\n", cas++);
        exc.clear();
        ans_str.clear();
        ans = -INF;
        for (int i = 0; i < n; i++) {
            input(word);
            for (int j = 0; j < (int)word.size(); j++) {
                if (word[j] >= 'A' && word[j] <= 'Z') {
                    word[j] = word[j] - 'A' + 'a';
                }
            }
            exc.insert(word);
        }
        for (int i = 0; i < m; i++) {
            word = "";
            while (word.empty()) getline(cin, word);
            int k = judge(word);
            if (k > ans) {
                ans_str.clear();
                ans_str.push_back(word);
                ans = k;
            } else if (k == ans) {
                ans_str.push_back(word);
            }
        }
        for (int i = 0; i < (int)ans_str.size(); i++) {
            print(ans_str[i]);
        }
        puts("");
    }
    return 0;
}

