#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;
const int ALPHA = 26;

vector<int> value;
string word;
int n;

llint solve(int c) {
    int v = value[c];
    unordered_map<llint, llint> mp;
    llint cnt = 0;
    llint sum = 0;
    llint res = 0;

    for (int i = 0; i < n; i++) {
        if (word[i] - 'a' == c) {
            if (cnt == 0) {
                sum = 0;
                mp[0] = 1;
            } else {
                llint s = sum + v * (cnt - 1);
                res += mp[s];
                mp[s + v]++;
            }
            cnt++;
        } else {
            sum += value[word[i] - 'a'];
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int a;
    llint ans = 0;
    for (int i = 0; i < ALPHA; i++) {
        input(a);
        value.push_back(a);
    }
    input(word);
    n = word.size();

    for (int i = 0; i < ALPHA; i++) {
        ans += solve(i);
    }
    print(ans);
    return 0;
}

