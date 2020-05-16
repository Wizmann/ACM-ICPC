// 题意
// 给定N个人和M个组。一个组可以包含多个人，但是一个人只能在一个组里。（一对多）
// 现在规定每个组不能超过K人，每个人必须在一个组里。问K的最小值。
// 
// 做法
// 使用匈牙利算法，规定二分图左边的点为“一对多”的“一”，右边的点为“多”。右边的点存储一个所有的匹配。
// 进行新的匹配时，判断右边的点是否超过限制。如果否，则新加一个匹配。
// 整体与匈牙利算法类似。
//
// 本题中还需要二分判断K的最小值。

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
#include <sstream>
#include <cassert>

using namespace std;

typedef long long llint;

const int SIZE = 1111;

vector<string> split_string(const string& line, char delim) {
    std::istringstream stream(line);
    string token;
    vector<string> res;
    while (std::getline(stream, token, delim)) {
        res.push_back(token);
    }
    return res;
}

class MultiHungary {
public:
    MultiHungary(int left_, int right_) : left(left_), right(right_) {
        g = vector<vector<int> >(left);
        for (int i = 0; i < left; i++) {
            g[i] = vector<int>(right, 0);
        }
        caps = vector<int>(right, 0);
    }

    void setCapacity(int idx, int cap) {
        caps[idx] = cap;
    }

    void addEdge(int l, int r) {
        g[l][r] = 1;
    }
    

    // `all_match` indicates if all nodes on the left 
    // are matched with one of the right nodes
    int match(bool& match_all_left, bool must_match_all_left) {
        int res = 0;
        match_all_left = true;
        pre = vector<vector<int> >(right);
        for (int i = 0; i < left; i++) {
            visited = vector<bool>(right, false);
            if (find_path(i)) {
                res++;
            } else {
                match_all_left = false;
            }

            if (must_match_all_left && !match_all_left) {
                return -1;
            }
        }

        return res;
    }
private:
    bool find_path(int cur) {
        for (int i = 0; i < right; i++) {
            if (g[cur][i] && !visited[i]) {
                visited[i] = true;
                if (pre[i].size() < caps[i]) {
                    pre[i].push_back(cur);
                    return true;
                }
                for (int j = 0; j < pre[i].size(); j++) {
                    int& p = pre[i][j];
                    if (find_path(p)) {
                        p = cur;
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    int left, right;
    vector<vector<int> > g;
    vector<int> caps;
    vector<vector<int> > pre;
    vector<bool> visited;
};

char buffer[2048];

int main() {
    int n, m;

    while (scanf("%d%d\n", &n, &m) != EOF) {
        if (n + m == 0) {
            break;
        }

        MultiHungary mh(n, m);

        for (int i = 0; i < n; i++) {
            fgets(buffer, 2048, stdin);
            string line(buffer);
            // puts(line.c_str());
            vector<string> tokens = split_string(line, ' ');
            int tn = tokens.size();
            for (int j = 1; j < tn; j++) {
                int g = atoi(tokens[j].c_str());
                mh.addEdge(i, g);
            }
        }

        // binary search
        int l = 1;
        int r = n;
        while (l <= r) {
            int mid = (l + r) / 2;

            for (int i = 0; i < m; i++) {
                mh.setCapacity(i, mid);
            }

            bool match_all_left = true;
            mh.match(match_all_left, true);
            if (match_all_left) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}

