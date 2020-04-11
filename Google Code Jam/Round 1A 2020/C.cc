// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1355               
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int my[4] = {-1, 0, 1, 0};
const int mx[4] = {0, 1, 0, -1};

class Solution {
public:
    Solution(vector<vector<int> >& matrix_) : matrix(matrix_) {
        n = matrix.size();
        m = matrix[0].size();

        neighbour.resize(n);
        for (int i = 0; i < n; i++) {
            neighbour[i].resize(m);
            for (int j = 0; j < m; j++) {
                neighbour[i][j] = {
                    i - 1 >= 0? 1: -1,
                    j + 1 < m ? 1: -1,
                    i + 1 < n ? 1: -1,
                    j - 1 >= 0? 1: -1
                };
            }
        }
    }

    llint solve() {
        queue<pair<int, int> > q[2];

        llint tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tot += matrix[i][j];
                q[0].push({i, j});
            }
        }

        int p = 0;
        llint res = 0;
        while (true) {
            res += tot;
            int eliminated = 0;
            set<pair<int, int> > st;
            while (!q[p].empty()) {
                auto cur = q[p].front();
                q[p].pop();

                int y = cur.first;
                int x = cur.second;

                if (matrix[y][x] == -1) {
                    continue;
                }

                if (!willEliminate(y, x)) {
                    continue;
                }
                st.insert({y, x});
            }

            for (auto ep : st) {
                int y = ep.first;
                int x = ep.second;
                eliminated++;
                tot -= matrix[y][x];
                matrix[y][x] = -1;
                for (int i = 0; i < 2; i++) {
                    int k1 = i;
                    int k2 = (i + 2) % 4;
                    auto np1 = getNeighbour(y, x, k1);
                    int ny1 = np1.first;
                    int nx1 = np1.second;

                    auto np2 = getNeighbour(y, x, k2);
                    int ny2 = np2.first;
                    int nx2 = np2.second;

                    if (ny1 == -1 || nx1 == -1) {
                        if (ny2 != -1 && nx2 != -1) {
                            neighbour[ny2][nx2][k1] = -1;
                        }
                    }
                    if (ny2 == -1 || nx2 == -1) {
                        if (ny1 != -1 && nx1 != -1) {
                            neighbour[ny1][nx1][k2] = -1;
                        }
                    }
                    if (ny1 != -1 && ny2 != -1 && nx1 != -1 && nx2 != -1) {
                        int delta = max(abs(nx2 - nx1), abs(ny2 - ny1));
                        neighbour[ny1][nx1][k2] = delta;
                        neighbour[ny2][nx2][k1] = delta;
                        if (getNeighbour(ny1, nx1, k2) != pair<int, int>(ny2, nx2)) {
                            assert(false);
                        }
                        if(getNeighbour(ny2, nx2, k1) != pair<int, int>(ny1, nx1)) {
                            assert(false);
                        }
                    }
                    if (ny1 != -1 || nx1 != -1) {
                        q[p ^ 1].push({ny1, nx1});
                        assert(0 <= ny1 && ny1 < n && 0 <= nx1 && nx1 < m);
                    }
                    if (ny2 != -1 || nx2 != -1) {
                        q[p ^ 1].push({ny2, nx2});
                        assert(0 <= ny2 && ny2 < n && 0 <= nx2 && nx2 < m);
                    }
                }
            }
            if (eliminated == 0) {
                break;
            }
            p = p ^ 1;

            /*
            puts("\n---");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] != -1) {
                        printf("%d ", matrix[i][j]);
                    } else {
                        printf("x ");
                    }
                }
                puts("");
            }
            puts("---");
            print(tot);
            */
        }
        return res;
    }

    pair<int, int> getNeighbour(int y, int x, int k) {
        if (neighbour[y][x][k] != -1) {
            int g = neighbour[y][x][k];
            int ny = y + g * my[k];
            int nx = x + g * mx[k];
            assert(0 <= ny && ny < n && 0 <= nx && nx < m);
            return {ny, nx};
        }
        return {-1, -1};
    }

    bool willEliminate(int y, int x) {
        llint comp = 0;
        llint cnt = 0;
        for (int k = 0; k < 4; k++) {
            auto np = getNeighbour(y, x, k);
            if (np.first == -1 || np.second == -1) {
                continue;
            }
            int ny = np.first;
            int nx = np.second;
            comp += matrix[ny][nx];
            cnt++;
        }
        return (1LL * cnt * matrix[y][x] < comp);
    }
private:
    int n, m;
    vector<vector<int> > matrix;
    vector<vector<vector<int> > > neighbour;
};

int main() {
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        int n, m;
        input(n >> m);
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("Case #%d: ", ++case_);
        print(Solution(matrix).solve());
    }
    return 0;
}

