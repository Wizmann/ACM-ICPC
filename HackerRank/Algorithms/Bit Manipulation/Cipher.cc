#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 2222222;

int n, k;

char bits[SIZE];
char res[SIZE];

int main() {
	input(n >> k);
	scanf("%s", bits);
	
	memset(res, 0, sizeof(res));
	deque<int> dq;
	int tail = 0;
	
	for (int i = n - 1; i >= 0; i--) {
		int p = i + k - 1;
		int cur = bits[p] - '0';
		cur ^= tail;
		res[i] = cur + '0';
		tail ^= cur;
		dq.push_back(cur);
		if (dq.size() > k - 1) {
			tail ^= *dq.begin();
			dq.pop_front();
		}
	}
	
	puts(res);
	return 0;
}
