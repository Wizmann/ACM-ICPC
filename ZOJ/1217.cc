// Result: 2015-09-13 18:38:34	Accepted	1217	C++0x	1000	11120	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int mx[] = {0, 1, 0, -1};
const int my[] = {-1, 0, 1, 0};

struct Node {
    uint64_t prev;
    uint8_t prev_mv;
    uint32_t step;
};

class Solution {
const uint64_t FINAL_STATUS = 123456789;
const uint64_t INF = numeric_limits<uint64_t>::max();
public:
    void init() {
        uint64_t init_status = FINAL_STATUS;
        visited[init_status] = {INF, 4, 0};
        q.push(init_status);
        while (!q.empty()) {
            auto cur_status = q.front();
            q.pop();

            uint32_t step = visited[cur_status].step;

            for (int i = 0; i < 9; i++) {
                for (uint8_t j = 0; j < 4; j++) {
                    uint64_t next_status = do_move(cur_status, i, j);
                    if (next_status == INF) {
                        continue;
                    }
                    auto iter = visited.find(next_status);
                    if (iter != visited.end()) {
                        continue;
                    }
                    visited[next_status] = {cur_status, j, step + 1};
                    q.push(next_status);
                }
            }
        }
    }
    string solve(uint64_t status) {
        return get_steps(status);
    }
private:
    string get_steps(uint64_t status) {
        if (visited.find(status) == visited.end()) {
            return "unsolvable";
        }
        vector<uint8_t> steps;
        while (status != numeric_limits<uint64_t>::max()) {
            steps.push_back(visited[status].prev_mv);
            status = visited[status].prev;
        }
        string res = "";
        
        const char mvchar[] = {'u', 'r', 'd', 'l'};
        for (auto step: steps) {
            if (step >= 0 && step < 4) {
                res += mvchar[step];
            }
        }
        return res;
    }

    uint64_t do_move(uint64_t status, int pos, int mv) {
        int y = pos / 3;
        int x = pos % 3;
        int ny = y + my[mv];
        int nx = x + mx[mv];

        if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3) {
            return numeric_limits<uint64_t>::max();
        }

        int next_pos = ny * 3 + nx;
        auto str = to_string(status);
        
        if (str[next_pos] != '9') {
            return numeric_limits<uint64_t>::max();
        }
        
        swap(str[pos], str[next_pos]);
        uint64_t res = 0;
        for (auto c: str) {
            res = res * 10 + c - '0';
        }
        //print(status << " -> " << res);
        return res;
    }
private:
    unordered_map<uint64_t, Node> visited;
    queue<uint64_t> q;
};

int main() {
    freopen("input.txt", "r", stdin);
    char tmp[300];
    Solution S;
    S.init();
    while (true) {
        uint64_t init_status = 0;
        if (!fgets(tmp, 2333, stdin)) {
            break;
        }
        if (!isdigit(*tmp) && *tmp != 'x') {
            continue;
        }
        for (int i = 0; tmp[i]; i++) {
            if (!isdigit(tmp[i]) && tmp[i] != 'x') {
                continue;
            }
            if (tmp[i] == 'x') {
                tmp[i] = '9';
            }
            init_status = init_status * 10 + (tmp[i] - '0');
        }
        
        auto ans = S.solve(init_status);
        printf("%s\n", ans.c_str());
    }
    return 0;
}
