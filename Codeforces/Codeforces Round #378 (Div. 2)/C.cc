#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

struct Monster {
    int nr;
    llint weight;
};

int n;
int m;
vector<Monster> monsters;
vector<llint> results;
vector<string> answer;

template<typename Container>
pair<typename Container::iterator, typename Container::iterator> 
get_adjacent_iter(
        const Container& container, typename Container::iterator iter) {
    auto iter_pre = iter;
    if (iter_pre != container.begin()) {
        iter_pre--;
    }

    auto iter_next = iter;
    iter_next++;
    if (iter_next == container.end()) {
        iter_next--;
    }

    return {iter_pre, iter_next};
}

bool solve_one(llint u) {
    list<Monster> mon_unit;
    int cnt = 0;
    llint maxi = 0;

    while (u > 0 && !monsters.empty()) {
        u -= monsters.rbegin()->weight;
        auto mon = *monsters.rbegin();
        mon_unit.push_back(mon);
        maxi = max(maxi, mon.weight);
        monsters.pop_back();
        cnt++;
    }
    if (u != 0) {
        return false;
    }

    reverse(mon_unit.begin(), mon_unit.end());

    auto iter = mon_unit.end();
    while (cnt > 1) {
        if (iter == mon_unit.end()) {
            for (auto jter = mon_unit.begin(); jter != mon_unit.end(); jter++) {
                if (jter->weight != maxi) {
                    continue;
                }

                auto iter_pair = get_adjacent_iter(mon_unit, jter);
                auto jter_pre = iter_pair.first;
                auto jter_next = iter_pair.second;

                if (jter->weight > jter_pre->weight 
                        || jter->weight > jter_next->weight) {
                    iter = jter;
                    break;
                }
            }

            if (iter == mon_unit.end()) {
                return false;
            }
            continue;
        }

        // print("cur maxi:" << ' ' << iter->weight << ' ' << iter->nr);

        auto iter_pair = get_adjacent_iter(mon_unit, iter);
        auto iter_pre = iter_pair.first;
        auto iter_next = iter_pair.second;

        if (iter->weight > iter_pre->weight) {
            iter->weight += iter_pre->weight;
            mon_unit.erase(iter_pre);
            cnt--;

            answer.push_back(to_string(iter->nr) + " L");
            (iter->nr)--;
        } else if (iter->weight > iter_next->weight) {
            iter->weight += iter_next->weight;
            mon_unit.erase(iter_next);
            cnt--;

            answer.push_back(to_string(iter->nr) + " R");
        } else {
            return false;
        }

        auto jter = iter;
        jter++;

        while (jter != mon_unit.end()) {
            jter->nr--;
            jter++;
        }
    }
    return true;
}

bool solve() {
    for (int i = 0; i < m; i++) {
        llint u = *results.rbegin();
        results.pop_back();
        if (!solve_one(u)) {
            return false;
        }
    }
    return monsters.empty();
}

int main() {
    input(n);
    monsters.resize(n);

    for (int i = 0; i < n; i++) {
        monsters[i].nr = i + 1;
        input(monsters[i].weight);
    }

    input(m);
    results.resize(m);
    for (int i = 0; i < m; i++) {
        input(results[i]);
    }

    if (solve()) {
        puts("YES");
        for (auto line: answer) {
            print(line);
        }
    } else {
        puts("NO");
    }

    return 0;
}
