//Result: 10115 Automatic Editing   Accepted    C++ 0.016   2014-01-12 11:14:16
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

typedef pair<string, string> pss;
#define mpss(a, b) make_pair<string, string>(string(a), string(b))

int n;
vector<pss> vec;
string s;

bool do_replace(string& ss, const string& a, const string& b)
{
    string::size_type pos = ss.find(a);
    if (pos == string::npos) {
        return false;
    }
    ss.replace(pos, a.length(), b);
    return true;
}

void do_getline(string& ss) {
    getline(cin, ss);
}

int main()
{
    freopen("input.txt", "r", stdin);
    string a, b;
    while(input(n) && n) {
        do_getline(s);
        vec.clear();
        for (int i = 0; i < n; i++) {
            do_getline(a);
            do_getline(b);
            vec.push_back(mpss(a, b));
        }
        do_getline(s);
        do {
            for (int i = 0; i < n; i++) {
                string& a = vec[i].first;
                string& b = vec[i].second;
                while (do_replace(s, a, b)) {
                    // pass
                }
            }
        } while(0);

        print(s);
    }
    return 0;
}

