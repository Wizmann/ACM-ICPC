#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
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

struct Student {
    string name;
    int grade;
    int sex;
    int number;
};

vector<Student> students;
map<string, int> nameidx;
map<int, vector<int> > gradeidx;

char name[10000];

int main() {
    int n;
    input(n);


    int grade, sex, number;
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d%d", name, &grade, &sex, &number);
        students.push_back({name, grade, sex, number});

        nameidx[name] = i;
        gradeidx[grade].push_back(i);
    }

    for (auto& p : gradeidx) {
        sort(p.second.begin(), p.second.end(), 
                [&](const int a, const int b) {
                    return students[a].name < students[b].name;
                });
    }

    int Q;
    input(Q);
    while (Q--) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            scanf("%s", name);
            int idx = nameidx[name];
            auto& s = students[idx];
            printf("%d %d %d\n", s.grade, s.number, s.sex);
        } else {
            scanf("%d", &grade);
            for (auto idx : gradeidx[grade]) {
                auto& s = students[idx];
                puts(s.name.c_str());
            }
        }
    }

    return 0;
}

/*

^^^TEST^^^
5
N 28 2 7475
UN 83 2 27550
EXF 5 2 17298
OVYNH 51 2 14827
XNV 53 1 7591
2
1
XNV
2
27
------
53 7591 1
$$$TEST$$$


^^^TEST^^^
5
N 1 2 7475
UN 1 2 27550
EXF 1 2 17298
OVYNH 1 2 14827
XNV 1 1 7591
2
1
XNV
2
1
------
1 7591 1
EXF
N
OVYNH
UN
XNV
$$$TEST$$$
*/
