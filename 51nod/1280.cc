#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;
typedef unsigned long long ullint;

const ullint MOD = 0xdeadbeefULL;

int n;
vector<int> nums;
unordered_map<llint, llint> mp;

ullint fastpow(ullint a, ullint b) {
	ullint res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}

ullint calc(bool do_calc) {
	ullint h = 0;
	ullint res = 0;
	unordered_set<int> st;
	for (int i = 0; i < n; i++) {
		if (st.find(nums[i]) == st.end()) {
			h = (h + fastpow(2, nums[i])) % MOD;
			st.insert(nums[i]);
		}
		if (!do_calc) {
			mp[h]++;
		} else {
			res += mp[h];
		}
	}
	return res;
}

int main() {
	input(n);
	nums.resize(n);
	
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
		mp[nums[i]] = -1;
	}
	
	int idx = 0;
	for (auto& p: mp) {
		p.second = idx++;
	}
	
	for (auto& num: nums) {
		num = mp[num];
	}
	
	calc(false);
	
	reverse(nums.begin(), nums.end());
	ullint ans = calc(true);

	print(ans);
	
	return 0;
}