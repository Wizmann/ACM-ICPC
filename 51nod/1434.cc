#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1000111;

vector<llint> primes;

void init() {
	vector<bool> sieve(SIZE, true);
	for (int i = 2; i < SIZE; i++) {
		if (!sieve[i]) {
			continue;
		}
		primes.push_back(i);
		for (llint j = 2; j * i < SIZE; j++) {
			sieve[j * i] = false;
		}
	}
}

llint solve(int n) {
	if (n == 1) {
		return 2;
	}
	llint res = 1;
	for (auto prime: primes) {
		if (prime > n) {
			break;
		}
		
		int cnt = 0;
		llint t = 1;
		while (t <= n) {
			cnt++;
			t *= prime;
		}
		t /= prime;
		res = max(res, (n / t + 1) * t);
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	int n;
	input(T);
	init();
	while (T--) {
		input(n);
		print(solve(n));
	}
	return 0;
}
