#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
vector<int> ns;
vector<int> hashL, hashR;

void getD(int start, int offset, int item, vector<int>& hash) {
    fill(hash.begin(), hash.end(), 0);
    hash[n] = 1;
    int s = 0;
    for (int i = start; i >= 0 && i < ns.size(); i += offset) {
        if (ns[i] > item) {
            s++;
        } else if (ns[i] < item) {
            s--;
        }
        hash[s + n]++;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n);
    ns.resize(n);
    hashL.resize(n * 2 + 1);
    hashR.resize(n * 2 + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }
    
    for (int i = 0; i < n; i++) {
        getD(i - 1, -1, ns[i], hashL);
        getD(i + 1, 1, ns[i], hashR);
        
        int s = 0;
        for (int i = -n; i <= n; i++) {
            s += hashL[i + n] * hashR[-i + n];
        }
        printf("%d ", s);
    }
    puts("");
    return 0;
}
