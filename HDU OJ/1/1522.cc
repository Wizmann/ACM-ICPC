//Result: 2013-12-26 14:42:59   Accepted    1522    15MS    4564K   2343 B  G++ Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 512;

int n;
vector<string> love[SIZE * 2];
vector<string> name;
map<string, int> mp;
int g[SIZE * 2][SIZE * 2];
int choice[SIZE * 2];

void solve()
{
    queue<int> q;

    // push all the boys in the queue
    for (int i = 0; i < n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            int gg = mp[love[now][i]];
            if (choice[gg] == -1 || g[gg][choice[gg]] < g[gg][now]) {
                
                if (choice[gg] != -1) {
                    choice[choice[gg]] = -1;
                    q.push(choice[gg]);
                }
                choice[gg] = now;
                if(choice[now] != -1) choice[choice[now]] = -1;
                choice[now] = gg;
                break;
            }
        }
    }
}

void init()
{
    memset(choice, -1, sizeof(choice));
    memset(g, 0, sizeof(g));
    mp.clear();
    name.clear();
    for (int i = 0; i < SIZE * 2; i++) {
        love[i].clear();
    }
}   

int main()
{
    string str;
    while (input(n)) {
        init();
        
        for (int i = 0; i < n * 2; i++) {
            string pa, pb;
            if (i < n) {
                pa = "B";
                pb = "G";
            } else {
                pa = "G";
                pb = "B";
            }
            input(str);
            name.push_back(pa + str);
            for (int j = 0; j < n; j++) {
                input(str);
                love[i].push_back(pb + str);
            }
        }

        for (int i = 0; i < n * 2; i++) {
            mp[name[i]] = i;
        }

        for (int i = 0; i < n * 2; i++) {
            for (int j = 0; j < n; j++) {
                const string& ss = love[i][j];
                g[i][mp[ss]] = n - j;
            }
        }

        solve();
        for (int i = 0; i < n; i++) {
            print(name[i].substr(1, 1000) << ' ' << name[choice[i]].substr(1, 1000));
        }
    }
    return 0;
}
