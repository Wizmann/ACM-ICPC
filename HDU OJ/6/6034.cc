#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;
const int MOD = 1000000000 + 7;

int n, m;
vector<string> nums;
vector<llint> mods;
vector<vector<int> > mp;
vector<bool> leading;
char buffer[SIZE];

void init() {
    nums.reserve(SIZE);
    mods = vector<llint>(SIZE, 0);
    mods[0] = 1;

    for (int i = 1; i < SIZE; i++) {
        mods[i] = 1LL * mods[i - 1] * 26 % MOD;
    }
}

bool cmp(int a, int b) {
    assert(mp[a].size() == m * 2);
    for (int i = m * 2 - 1; i >= 0; i--) {
        assert(mp[a][i] < 26);
        assert(mp[b][i] < 26);
        if (mp[a][i] != mp[b][i]) {
            return mp[a][i] < mp[b][i];
        }
    }
    return true;
}

int do_solve() {
    vector<int> vs;
    for (int i = 0; i < 26; i++) {
        vs.push_back(i);
    }
    sort(vs.begin(), vs.end(), cmp);

    int ex = -1;
    for (int i = 0; i < 26; i++) {
        if (!leading[vs[i]]) {
            ex = vs[i];
            break;
        }
    }

    vector<int> ms(26, 0);
    int cur = 1;
    for (int i = 0; i < 26; i++) {
        int v = vs[i];
        if (v == ex) {
            continue;
        }
        ms[v] = cur++;
    }

    llint res = 0;
    for (int i = 0; i < n; i++) {
        const string& num = nums[i];
        for (int j = 0; j < num.size(); j++) {
            res = (1LL * res + 1LL * mods[j] * ms[(num[j] - 'a')]) % MOD;
        }
    }
    return res;
}

int solve() {
    mp = vector<vector<int> >(26, vector<int>(m * 2, 0));
    leading = vector<bool>(26, false);
    for (int i = 0; i < n; i++) {
        const string& num = nums[i];
        for (int i = 0; i < num.size(); i++) {
            mp[num[i] - 'a'][i]++;
        }

        if (num.size() > 1) {
            leading[*num.rbegin() - 'a'] = true;
        }
    }

    for (int i = 0; i < 26; i++) {
        int g = 0;
        for (int j = 0; j < m * 2; j++) {
            int u = mp[i][j] + g;
            mp[i][j] = u % 26;
            g = u / 26;
        }
    }

    return do_solve();
}

int main() {
    init();
    int case_ = 0;
    while (input(n)) {
        printf("Case #%d: ", ++case_);
        nums.clear();

        m = 0;

        for (int i = 0; i < n; i++) {
            scanf("%s", buffer);
            int len = strlen(buffer);
            m = max(m, len);
            reverse(buffer, buffer + len);
            nums.push_back(buffer);
        }

        print(solve());
    }
    return 0;
}
