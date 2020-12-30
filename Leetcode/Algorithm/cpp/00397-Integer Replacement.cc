typedef long long llint;
class Solution {
public:
    int integerReplacement(llint n) {
        if (n == 1) {
            return 0;
        }
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }
        if (n % 2 == 0) {
            return mp[n] = (integerReplacement(n / 2) + 1);
        } else {
            int a = integerReplacement(n + 1);
            int b = integerReplacement(n - 1);
            return mp[n] = (min(a, b) + 1);
        }
    }
private:
    unordered_map<llint, int> mp;
};
