// Result : 10132   File Fragmentation  Accepted    C++ 0.012   2013-12-22 08:11:38
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 512;

vector<string> vec[SIZE];

string solve(int len) 
{
    map<string, int> mp;
    for (int i = 1; i < len; i++) {
        int l = i;
        int r = len - i;

        for (int j = 0; j < (int)vec[l].size(); j++) {
            for (int k = 0; k < (int)vec[r].size(); k++) {
                mp[vec[l][j]+vec[r][k]]++;
                mp[vec[r][k]+vec[l][j]]++;
            }
        }
    }

    int ans = 0;
    string res;

    for (map<string, int>::iterator iter = mp.begin();
            iter != mp.end();
            ++iter) {
        string s = iter -> first;
        int cnt = iter -> second;
        if (cnt > ans && (int)s.length() == len) {
            ans = cnt;
            res = s;
        }
    }

    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    string s;
    input(T);
    getline(cin, s, '\n');
    getline(cin, s, '\n');
    while (T--) {
        int sum = 0;
        int n = 0;
        for (int i = 0; i < SIZE; i++) {
            vec[i].clear();
        }
        

        while (!cin.eof()) {
            getline(cin, s, '\n');
            if (s.empty()) {
                break;
            }
            n++;
            sum += s.size();
            vec[s.size()].push_back(s);
        }
        print(solve(sum * 2/n));
        if (T) puts("");
    }
    return 0;
}

