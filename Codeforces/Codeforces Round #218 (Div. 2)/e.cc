#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

struct node {
    int pos, nr;
    node(){}
    node(int ipos, int inr):
            pos(ipos), nr(inr) {}

    bool operator < (const node& x) const 
    {
        return pos < x.pos;
    }
};

const int SIZE = 300008;

node station[SIZE];
llint leftsum[SIZE];

llint n, k;

int main() 
{
    input(n);
    for (int i = 0; i < n; i++) {
        input(station[i].pos);
        station[i].nr = i + 1;
    }
    input(k);
    sort(station, station + n);
    for (int i = 1; i < n; i++) {
        leftsum[i] = leftsum[i-1] + station[i].pos;
    }
    
    llint f = 0;
    for (int i = 1; i <= k; i++) {
        f += (llint)station[i].pos * i - leftsum[i-1];
    }
    
    llint res = f;
    int pos = 0;
    k--;
    for (int i = 1; i < n - k; i++) {
        f += station[i+k].pos * k;
        f -= leftsum[i+k-1] * 2;
        f += leftsum[i-1] * 2 ;
        f += station[i-1].pos * k;
        if (f < res) {
            res = f;
            pos = i;
        }
    }
    for (int i=0; i<=k; i++) {
        printf("%d ", station[pos + i].nr);
    }
    return 0;
}
