#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1000100;
const int INF = 0x3f3f3f3f;

map<int, int> mp;
map<int, int> tp;

int A[SIZE];
int B[SIZE];
long long n, m, p;
set<int> res;


void do_search(int x)
{
    tp.clear();
    int sum = 0;

    for (long long i = x ; i < n && i < m * p + x; i+=p) {
        
        if (mp.find(A[i]) != mp.end()) {
            tp[A[i]]++;
            if (tp[A[i]] <= mp[A[i]]) sum++;
        }
    }

    for (long long i = m * p + x; i < n; i += p) {
        if (sum == m) {
            res.insert(i - m * p);
            //print(x << ' ' << i - m * p);
        }

        int pre = A[i - m * p];
        int now = A[i];

        if (mp.find(pre) != mp.end()) {
            tp[pre]--;
            if (tp[pre] < mp[pre]) sum--;
        }

        if (mp.find(now) != mp.end()) {
            tp[now]++;
            if (tp[now] <= mp[now]) sum++;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    input(n >> m >> p);
    mp.clear();
    memset(A, INF, sizeof(A));
    for (int i = 0; i < n; i++) {
        input(A[i]);
    }
    for (int i = 0; i < m; i++) {
        input(B[i]);
        mp[B[i]]++;
    }
    
    n += p;

    
    for (int i = 0; i < p; i++) {
        //print(i);
        do_search(i);
    }

    print(res.size());

    for (set<int>::iterator iter = res.begin();
            iter != res.end();
            ++iter) {
        if (iter != res.begin()) printf(" ");
        printf("%d", *iter + 1);
    }
    return 0;
}


