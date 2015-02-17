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
    input(n);
    cards.resize(n);
    for (int i = 0; i < n; i++) {
        input(cards[i].step);
    }

    for (int i = 0; i < n; i++) {
        input(cards[i].cost);
    }

    unordered_map<int, int> mp;
    for (auto& card: cards) {
        if (mp.find(card.step) == mp.end()) {
            mp[card.step] = INF;
        }
        mp[card.step] = min(mp[card.step], card.cost);
    }

    for (int i = 0; i < n; i++) {
        int thres = mp.find(1) != mp.end()? mp[1]: INF;
        for (auto& p: mp) {
            auto step = p.first;
            auto cost = p.second;
            
            if (step != 1 && cost >= thres) {
                continue;
            }
            
            int g = gcd(step, cards[i].step);

            if (mp.find(g) == mp.end()) {
                mp[g] = INF;
            }
            
            if (g == step) {
                mp[g] = min(mp[g], cost);
            }

            mp[g] = min(mp[g], cost + cards[i].cost);
        }
    }

    if (mp.find(1) == mp.end()) {
        print("-1");
    } else {
        print(mp[1]);
    }

    return 0;
}

