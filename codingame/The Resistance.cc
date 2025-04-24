#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// 使用 64 位大质数作为哈希模数（常用安全质数）
const uint64_t MOD = 2305843009213693951ULL;
const int BASE = 3;

// 摩斯码映射表
string morse_map[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
    "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--.."
};

// 单词转摩斯码
string wordToMorse(const string& word) {
    string res;
    for (char c : word) {
        res += morse_map[c - 'A'];
    }
    return res;
}

// 计算摩斯码的 rolling hash 值
uint64_t hashMorse(const string& morse) {
    uint64_t h = 0;
    for (char c : morse) {
        int val = (c == '.') ? 1 : 2;
        h = (h * BASE + val) % MOD;
    }
    return h;
}

unordered_map<uint64_t, int> dict_hash;
vector<uint64_t> memo;

uint64_t dfs(const string& s, int i) {
    if (i == (int)s.size()) {
        return 1;
    }
    if (memo[i] != numeric_limits<uint64_t>::max()) return memo[i];

    uint64_t h = 0;
    uint64_t res = 0;

    for (int j = i; j < (int)s.size() && j - i <= 100; ++j) {
        int val = (s[j] == '.') ? 1 : 2;
        h = (h * BASE + val) % MOD;
        if (dict_hash.count(h)) {
            res += 1LL * dict_hash[h] * dfs(s, j + 1);
        }
    }

    return memo[i] = res;
}

int main() {
    string morse_input;
    int n;
    cin >> morse_input >> n;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        string morse = wordToMorse(word);
        dict_hash[hashMorse(morse)]++;
    }

    memo.assign(morse_input.size() + 1, numeric_limits<uint64_t>::max());

    cout << dfs(morse_input, 0) << endl;
    return 0;
}

/*
^^^^^TEST^^^^^
......-...-..---.-----.-..-..-..
5
HELL
HELLO
OWORLD
WORLD
TEST
-------------
2
$$$$TEST$$$$

^^^^^TEST^^^^^
-.-..---.-..---.-..--
5
CAT
KIM
TEXT
TREM
CEM
-------------
125
$$$$TEST$$$$


 */
