#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int n;
vector<pair<int, int> > nums;

int main() {
	input(n);
	
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		nums.push_back({x, i});
	}
	sort(nums.begin(), nums.end());
	
	llint ans = 0;
	
	set<int> st0;
	st0.insert(-1);
	st0.insert(n);
	for (const auto& p: nums) {
		int value = p.first;
		int pos = p.second;
		auto iter = st0.upper_bound(pos);
		int b = *iter;
		int a = *(--iter);
		ans -= (b - pos) * (pos - a) * value;
		st0.insert(pos);
	}
	
	reverse(nums.begin(), nums.end());
	
	set<int> st1;
	st1.insert(-1);
	st1.insert(n);
	for (const auto& p: nums) {
		int value = p.first;
		int pos = p.second;
		auto iter = st1.upper_bound(pos);
		int b = *iter;
		int a = *(--iter);
		ans += (b - pos) * (pos - a) * value;
		st1.insert(pos);
	}
	
	print(ans);
	return 0;
}