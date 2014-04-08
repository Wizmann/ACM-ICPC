//Result:   Wizmann URAL 1015   Accepted    1721 KB 78 ms   G++ 4.7.2 C++11 1665 B  2014-03-13 11:46:21
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 100100;
const int turnleft[] = {4, 6, 3, 2, 5, 1};
const int turndown[] = {1, 2, 6, 3, 4, 5};

int dice[6];
map<int, int> mp;
vector<int> vec[SIZE];

inline int make_hash()
{
    int v = 0;
    for (int i = 0; i < 6; i++) {
        v = v * 10 + dice[i];
    }
    return v;
}

void do_turn(const int* turn)
{
    int dd[6] = {0};
    for (int i = 0; i < 6; i++) {
        dd[i] = dice[i];
    }
    for (int i = 0; i < 6; i++) {
        dice[i] = dd[turn[i] - 1];
    }
}

int make_dice()
{
    int v = 0;;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                v = max(make_hash(), v);
                do_turn(turndown);
            }
            do_turn(turnleft);
        }
        do_turn(turndown);
    }
    return v;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, u, v;
    int idx = 0;
    input(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &dice[j]);
        }
        v = make_dice();
        
        if (mp.find(v) == mp.end()) {
            mp[v] = idx++;
        }
        
        u = mp[v]; 
        vec[u].push_back(i + 1);
    }
    
    print(idx);
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < (int)vec[i].size(); j++) {
            if (j) printf(" ");
            printf("%d", vec[i][j]);
        }
        if (!vec[i].empty()) {
            puts("");
        }
    }
    return 0;
}
