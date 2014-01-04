//Result: 10763 Foreign Exchange    Accepted    C++ 0.559   2013-12-22 06:44:52
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

#define mpii(a, b) make_pair<int, int>(int(a), int(b))

const int SIZE = 500100;

int n;

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    while (input(n) && n) {
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++) {
            input(a >> b);
            mp[mpii(a, b)]++;
        }
        
        bool flag = true;
        for (map<pair<int, int>, int>::iterator iter = mp.begin();
                iter != mp.end();
                ++iter) {
            pair<int, int> p = iter -> first;
            int m = iter -> second;
            
            if (!m) continue;
            
            pair<int, int> q = mpii(p.second, p.first);
            if (mp[q] != m) {
                flag = false;
                break;
            } else {
                mp[q] = 0;
            }
        }
        if (flag) {
            print("YES");
        } else {
            print("NO");
        }
    }
    return 0;
}
            

