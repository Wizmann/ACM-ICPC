#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 212345;

int n, m, q;
string A, B;
int kmp_next[SIZE];
unordered_map<int, int> mp;

void do_kmp() {
	kmp_next[0] = -1;
    
    for (int pre = -1, suf = 0; suf < B.size(); /* pass */) {
        if (pre == -1 || B[pre] == B[suf]) {
            suf++;
            pre++;
            
            kmp_next[suf] = pre;
        } else {
            pre = kmp_next[pre];
        }
    }
}

void do_find() {
	int p = 0;
	for (int i = 0; i < A.size(); i++) {
		while (p && A[i] != B[p]) {
			p = kmp_next[p];
		}
		if (A[i] == B[p]) {
			p++;
		}
		mp[p]++;
	}
}

void do_adjust() {
	for (int i = B.size(); i > 0; i--) {
		mp[kmp_next[i]] += mp[i];
	}
	for (int i = 0; i <= B.size(); i++) {
		mp[i] -= mp[i + 1];
	}
}

void kmp() {
    do_kmp();
    do_find();
    do_adjust();
}

int solve(int u) {
    return mp[u];
}

int main() {
	freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    input(A);
    input(B);

    kmp();
	
    int query = -1;
    while (q--) {
        scanf("%d", &query);
        printf("%d\n", solve(query));
    }
    
    return 0;
}
