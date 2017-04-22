#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

class HopcroftKarp {
public:
    HopcroftKarp(int n1_, int n2_): n1(n1_), n2(n2_) {
        g.resize(n1);
        mx.resize(n1);
        dsx.resize(n1);
        my.resize(n2);
        dsy.resize(n2);
        visited.resize(n1 + n2);
    }

    void AddEdge(int from, int to) {
        g[from].push_back(to);
    }

    int match() {
        int ans = 0;
        for (int i = 0; i < n1; i++) {
            mx[i] = -1;
        }
        for (int i = 0; i < n2; i++) {
            my[i] = -1;
        }

        while (bfs()) {
            fill(visited.begin(), visited.end(), false);
            for (int i = 0; i < n1; i++) {
                if (mx[i] == -1 && dfs(i)) {
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    bool bfs(){
        fill(dsx.begin(), dsx.end(), -1);
        fill(dsy.begin(), dsy.end(), -1);
        depth = INF;

        queue<int> q;
        
        for (int i = 0; i < n1; i++) {
            if(mx[i] == -1) {
                q.push(i);
                dsx[i] = 0;
            }
        }

        while (!q.empty()) {
            int x = q.front();
            if(dsx[x] > depth) {
                break;
            }
            
            for (auto y: g[x]) {
                if (dsy[y] == -1){
                    dsy[y] = dsx[x] + 1;
                    if(my[y] == -1) {
                        depth = dsy[y];
                    } else {
                        dsx[my[y]] = dsy[y] + 1;
                        q.push(my[y]);
                    }
                }
            }
            q.pop();
        }
        return depth != INF;
    }

    bool dfs(int x) {
        for (auto next: g[x]) {
            if (!visited[next] && dsy[next] == dsx[x] + 1) {
                visited[next] = true;
                if (my[next] != -1 && dsy[next] == depth) {
                    continue;
                }
                if (my[next] == -1 || dfs(my[next])){
                    my[next] = x;
                    mx[x] = next;
                    return true;
                }

            }
        }
        return false;
    }
private:
    int n1, n2;
    int depth;
    vector<int> mx, my;
    vector<int> dsx, dsy;
    vector<bool> visited;
    vector<vector<int> > g;
};

int main() {
    freopen("input.txt", "r", stdin);
    
    int n1, n2, k;
    input(n1 >> n2 >> k);

    HopcroftKarp S(n1, n2);
    int a, b;
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        S.AddEdge(a - 1, b - 1);
    }
    print(S.match());
    return 0;
}
