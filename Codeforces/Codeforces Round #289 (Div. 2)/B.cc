#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 128 + 19;
const int INF = 0x3f3f3f3f;

struct Pile {
    int nr;
    int height;
    vector<int> items;
};

int n, c;
vector<Pile> piles;

bool can_fill() {
    int max_height = 0;
    int min_height = INF;
    for (auto& pile: piles) {
        max_height = max(max_height, pile.height);
        min_height = min(min_height, pile.height);
    }
    return (max_height - min_height) <= c;
}

void do_fill(Pile& pile, int min_height) {
    for (int i = 0; i < min_height; i++) {
        pile.items.push_back(1);
    }

    for (int i = 1; i <= pile.height - min_height; i++) {
        pile.items.push_back(i);
    }
}

int main() {
    int a;
    input(n >> c);
    int min_pile = INF;
    for (int i = 0; i < n; i++) {
        input(a);
        auto pile = Pile();
        pile.nr = i;
        pile.height = a;
        piles.push_back(pile);

        min_pile = min(min_pile, pile.height);
    }
    sort(piles.begin(), piles.end(),
            [](const Pile& a, const Pile& b) -> bool {
                return a.height < b.height;
            });
    if (!can_fill()) {
        puts("NO");
        exit(0);
    }
    puts("YES");
    for (auto& pile: piles) {
        do_fill(pile, min_pile);
    }
    sort(piles.begin(), piles.end(),
            [](const Pile& a, const Pile& b) -> bool {
                return a.nr < b.nr;
            });
    for (auto& pile: piles) {
        for (auto& item: pile.items) {
            printf("%d ", item);
        }
        puts("");
    }
    return 0;
}
