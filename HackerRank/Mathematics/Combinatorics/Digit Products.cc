#include <bits/stdc++.h>
#include <cassert>

using namespace std;


#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1'000'000'000 + 7;
const int N = 111;

llint mypow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

llint AA[N];
llint INV[N];
llint DFS2[N][N][N];

llint A(int n, int m) {
    if (m > n) {
        return 0;
    }
    return AA[n] * INV[n - m] % MOD;
}

llint dfs2(int n, int c2, int c3) {
    if (n < c2 / 3 + c3 / 2) {
        return 0;
    }
    assert(n >= 0);
    if (n == 0) {
        return (c2 == 0 && c3 == 0)? 1: 0;
    }
    if (c2 < 0 || c3 < 0) {
        return 0;
    }
    if (DFS2[n][c2][c3] != -1) {
        return DFS2[n][c2][c3];
    }
    llint res = 0;
    res = (res + dfs2(n - 1, c2, c3)) % MOD;        // 1
    res = (res + dfs2(n - 1, c2 - 1, c3)) % MOD;    // 2
    res = (res + dfs2(n - 1, c2, c3 - 1)) % MOD;    // 3
    res = (res + dfs2(n - 1, c2 - 2, c3)) % MOD;    // 4
    res = (res + dfs2(n - 1, c2 - 1, c3 - 1)) % MOD;// 6
    res = (res + dfs2(n - 1, c2 - 3, c3)) % MOD;    // 8
    res = (res + dfs2(n - 1, c2, c3 - 2)) % MOD;    // 9
    return DFS2[n][c2][c3] = res;
}

llint solve2(int n, int c2, int c3) {
    return DFS2[n][c2][c3];
}

llint calc(int n, const vector<int>& k) {
    // cout << "calc: " << n << ' ' << k << endl;
    int tot = accumulate(k.begin(), k.end(), 0);
    if (n == 0) {
        return tot == 0? 1: 0;
    }
    tot -= k[2] + k[3];
    llint res = A(n, tot);
    for (int i = 4; i < 10; i++) {
        res = (res * INV[k[i]]) % MOD;
    }
    if (n >= tot) {
        res = res * solve2(n - tot, k[2], k[3]) % MOD;
    }
    return res;
}

vector<pair<int, int> > factors[10];

llint dfs(int cur, int n, const string& s, vector<int> k, bool lt) {
    if (cur == n) {
        auto ksum = accumulate(k.begin(), k.end(), 0);
        return ksum == 0? 1: 0;
    }
    llint res = 0;
    for (int i = 1; i <= 9; i++) {
        auto kk = k;
        bool flag = true;
        for (auto p : factors[i]) {
            kk[p.first] -= p.second;
            if (kk[p.first] < 0) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }

        if (lt) {
            res = (res + calc(n - cur - 1, kk)) % MOD;
        } else {
            if (i == s[cur]) {
                res = (res + dfs(cur + 1, n, s, kk, false)) % MOD;
            } else if (i < s[cur]) {
                res = (res + calc(n - cur - 1, kk)) % MOD;
            }
        }
    }
    return res;
}

llint do_solve(string s, llint k) {
    if (s == "0") {
        return 0;
    }
    int n = s.size();
    for (int i = 0; i < n; i++) {
        s[i] -= '0';
    }
    vector<int> ks(10, 0);
    for (int i = 2; i < 10; i++) {
        while (k % i == 0) {
            ks[i]++;
            k /= i;
        }
    }
    if (k != 1) {
        return 0;
    }
    llint res = 0;
    for (int i = 1; i < n; i++) {
        res = (res + calc(n - i, ks)) % MOD;
    }
    res = (res + dfs(0, n, s, ks, false)) % MOD;

    return res;
}

string minus_one(std::string a) {
    if (a == "1") {
        return "0";
    }
    int n = a.size();
    for (int i = 0; i < n; i++) {
        a[i] -= '0';
    }
    int g = -1;
    for (int i = n - 1; i >= 0; i--) {
        int u = int(a[i]) + g;
        g = 0;
        if (u < 0) {
            u += 10;
            g = -1;
        }
        a[i] = u;
    }
    int l = 0;
    while (a[l] == 0) {
        l++;
    }

    string res;
    for (/* pass */; l < n; l++) {
        res += '0' + a[l];
    }
    // cout << res << endl;
    return res;
}

llint solve(string a, string b, llint k) {
    llint va = 0;
    llint vb = 0;
    if (a != "1") {
        a = minus_one(a);
        va = do_solve(a, k);
    }
    vb = do_solve(b, k);
    return ((vb - va) % MOD + MOD) % MOD;
}

void test() {
    assert(calc(5, {0, 0, 2, 3, 0, 1, 0, 1, 0, 0}) == 300);
    assert(do_solve("20", 4) == 2); // 4, 14
    assert(do_solve("99999", 3780) == 300);
    assert(do_solve("10000000", 3780) == 15540);
    assert(do_solve("10000000", 32) == 784);
    assert(solve("10", "10000000", 3780) == 15540);
    assert(solve("10", "1000000", 40) == 364);
    assert(do_solve("6", 6) == 1);
    assert(minus_one("100") == "99");
    assert(minus_one("10000") == "9999");
    assert(minus_one("10001") == "10000");
    assert(minus_one("36") == "35");
    assert(do_solve("666", 66) == 0); 
    assert(do_solve("666", 12) == 19); 
    assert(do_solve("66666", 12) == 125); 
    assert(do_solve("666666", 16) == 226); 
    assert(do_solve("66666666", 8) == 329); 
    assert(do_solve("20", 3) == 2); // 3, 13
    assert(do_solve("0", 3) == 0);
    assert(do_solve("9", 3) == 1);
    assert(A(5, 3) == 60);
    assert(A(10, 2) == 90);
    assert(mypow(2, 10) == 1024);
    assert(do_solve("37", 6) == 4);
    assert(solve2(1, 1, 1) == 1);
    assert(do_solve("66", 6) == 5); // 6, 16, 23, 32, 61
    assert(do_solve("1", 6) == 0);
    assert(do_solve("1", 1) == 1);
    assert(do_solve("0", 1) == 0);
}

char buffer[111];

void init() {
    factors[2] = { { 2, 1 } };
    factors[3] = { { 3, 1 } };
    factors[4] = { { 2, 2 } };
    factors[5] = { { 5, 1 } };
    factors[6] = { { 2, 1 }, {3, 1} };
    factors[7] = { { 7, 1 } };
    factors[8] = { { 2, 3 } };
    factors[9] = { { 3, 2 } };

    AA[0] = 1;
    for (int i = 1; i < N; i++) {
        AA[i] = AA[i - 1] * i % MOD;
    }
    for (int i = 0; i < N; i++) {
        INV[i] = mypow(AA[i], MOD - 2);
    }

    memset(DFS2, -1, sizeof(DFS2));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                DFS2[i][j][k] = dfs2(i, j, k);
            }
        }
    }
}

int main()
{
    init();
    test();

    int t;
    input(t);

    string a(N, '\0');
    string b(N, '\0');
    for (int t_itr = 0; t_itr < t; t_itr++) {
        scanf("%s", buffer);
        a = std::string(buffer);

        scanf("%s", buffer);
        b = std::string(buffer);

        llint k;
        scanf("%lld", &k);

        llint result = solve(a, b, k);

        printf("Case %d: %lld\n", t_itr + 1, result);
    }

    return 0;
}

