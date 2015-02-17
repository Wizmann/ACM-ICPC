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

const int SIZE = 500;
const int INF = 0x3f3f3f3f;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

struct Card {
    int step;
    int cost;
};

int n;

vector<Card> cards;

int main() {
    freopen("D.txt", "r", stdin);
    input(n);
    cards.resize(n);
    for (int i = 0; i < n; i++) {
        input(cards[i].step);
    }

    for (int i = 0; i < n; i++) {
        input(cards[i].cost);
    }

    unordered_map<int, int> mps[2];
    for (auto& card: cards) {
        if (mps[0].find(card.step) == mps[0].end()) {
            mps[0][card.step] = INF;
        }
        mps[0][card.step] = min(mps[0][card.step], card.cost);
    }

    int ptr = 0;
    for (int i = 0; i < n - 1; i++) {
        auto& now = mps[ptr];
        auto& next = mps[ptr^1];

        ptr ^= 1;
        next.clear();
        for (int j = 0; j < n; j++) {
            int thres = now.find(1) != now.end()? now[1]: INF;
            for (auto& p: now) {
                auto step = p.first;
                auto cost = p.second;
                
                if (step != 1 && cost >= thres) {
                    continue;
                }
                
                int g = gcd(step, cards[j].step);

                if (next.find(g) == next.end()) {
                    next[g] = INF;
                }
                
                if (g == step) {
                    next[g] = min(next[g], cost);
                }

                next[g] = min(next[g], cost + cards[j].cost);
            }
        }
    }

    auto& mp = mps[ptr];

    if (mp.find(1) == mp.end()) {
        print("-1");
    } else {
        print(mp[1]);
    }

    return 0;
}

