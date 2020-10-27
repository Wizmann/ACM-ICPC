#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

vector<string> name;

struct Ship {
    int idx;
    llint speed;
};


int main() {
    int n;
    llint L;
    input(n, L);

    vector<Ship> ships(n);
    name.resize(n);
    char buffer[111];

    for (int i = 0; i < n; i++) {
        llint v;
        scanf("%s%lld", buffer, &v);
        name[i] = buffer;
        ships[i].idx = i;
        ships[i].speed = v;
    }

    sort(ships.begin(), ships.end(), [](const Ship& s1, const Ship& s2) {
        return s1.speed < s2.speed;
    });

    for (int i = 0; i < n - 1; i++) {
        llint loop = ships[i].speed * (i + 1) / L;
        llint rem = (ships[i].speed * (i + 1)) % L;
        printf("%s %lld %lld\n", name[ships[i].idx].c_str(), loop, L - rem);
    }
    puts(name[ships[n - 1].idx].c_str());

    return 0;
}
// Cautious: long long

/*
^^^TEST^^^
3 10
Smolensk
15
Shimakaze
14
Daring
13
----
Daring 1 7
Shimakaze 2 2
Smolensk
$$$TEST$$$$

^^^TEST^^^
3 10
fuck
15
Shimakaze
14
Daring
13
----
Daring 1 7
Shimakaze 2 2
fuck
$$$TEST$$$$

^^^TEST^^^
2 10
fuck
1
shit
2
----
fuck 0 9
shit
$$$TEST$$$$
*/
