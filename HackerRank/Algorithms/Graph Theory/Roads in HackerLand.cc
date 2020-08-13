#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef long long llint;

vector<string> split_string(string);

class DisjointSet {
public:
    DisjointSet(int n_) : n(n_), father(n_) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }

    void make_union(int a, int b) {
        father[find_father(a)] = find_father(b);
    }
private:
    int n;
    vector<int> father;
};

struct Edge {
    int dest, cost; 
};

vector<vector<Edge> > g;
map<int, llint> mp;

int dfs(int n, int pre, int cur) {
    int size = 0;
    for (auto e: g[cur]) {
        if (e.dest == pre) {
            continue;
        }
        int u = dfs(n, cur, e.dest);
        int v = n - u;
        mp[e.cost] += 1LL * u * v;
        size += u;
    }
    return size + 1;
}

string pairwiseDistance(int n, const vector<vector<int> > edges) {
    g.clear();
    g.resize(n + 1);
    mp.clear();
    for (const auto& e: edges) {
        g[e[0]].push_back({e[1], e[2]});
        g[e[1]].push_back({e[0], e[2]});
    }

    dfs(n, -1, 1);
    map<int, int> mp2;
    while (!mp.empty()) {
        auto iter = mp.begin();
        auto cur = *iter;
        mp.erase(iter);

        if (cur.second == 1) {
            mp2[cur.first] = 1;
            continue;
        }
        for (int i = 0; i < 60; i++) {
            if (cur.second & (1LL << i)) {
                mp[cur.first + i]++;
            }
        }
    }
    int maxi = mp2.rbegin()->first;
    string res(maxi + 1, '0');
    for (auto kv: mp2) {
        res[kv.first] = '1';
    }
    reverse(res.begin(), res.end());
    return res;
}

string roadsInHackerland(int n, vector<vector<int>> roads) {
    sort(roads.begin(), roads.end(), [](const vector<int>& r1, const vector<int>& r2) {
        return r1[2] < r2[2];
    });
    DisjointSet ds(n + 1);
    vector<vector<int> > edges;
    for (const auto& r: roads) {
        int a = r[0];
        int b = r[1];
        int c = r[2];

        if (ds.find_father(a) != ds.find_father(b)) {
            ds.make_union(a, b);
            edges.push_back(r);
        }
    }

    return pairwiseDistance(n, edges);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> roads(m);
    for (int roads_row_itr = 0; roads_row_itr < m; roads_row_itr++) {
        roads[roads_row_itr].resize(3);

        for (int roads_column_itr = 0; roads_column_itr < 3; roads_column_itr++) {
            cin >> roads[roads_row_itr][roads_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string result = roadsInHackerland(n, roads);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
