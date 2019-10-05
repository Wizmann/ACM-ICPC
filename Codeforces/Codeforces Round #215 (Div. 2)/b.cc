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

const int SIZE = 123456;

struct query {
    int val, pos;
    
    query(){}
    query(int ival, int ipos):
        val(ival), pos(ipos){}
    
    bool operator < (const query& q) const {
        return this -> val < q.val;
    }
};

vector<query> querys;
int A[SIZE];
int ans[SIZE];
char visit[SIZE];
int n, m;

int main()
{
    freopen("input.txt", "r", stdin);
    int a;
    input(n >> m);
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= n; i++) {
        input(A[i]);
    }
    for (int i = 1; i <= m; i++) {
        input(a);
        querys.push_back(query(a, i));
    }

    sort(querys.begin(), querys.end());
    m--;

    int sum = 0;
    for (int i = n; i > 0; i--) {
        if (!visit[A[i]]) {
            sum++;
            visit[A[i]] = 1;
        }

        while (m >= 0 && i == querys[m].val) {
            ans[querys[m].pos] = sum;
            m--;
        }
    }

    for (int i = 1; i <= (int)querys.size(); i++) {
        print(ans[i]);
    }

    return 0;
}



