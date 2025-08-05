typedef long long llint;
const int N = 111;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;
vector<llint> g[N];

class Graph {
public:
    Graph(int n_, vector<vector<int>>& edges) {
        n = n_;
        for (int i = 0; i < N; i++) {
            g[i] = vector<llint>(N, INF);
            g[i][i] = 0;
        }

        for (auto& e : edges) {
            int a = e[0];
            int b = e[1];
            g[a][b] = e[2];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int a = edge[0];
        int b = edge[1];
        int c = edge[2];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][a] + c + g[b][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        llint res = g[node1][node2];
        if (res >= INF) {
            return -1;
        }
        return res;
    }

private:
    int n;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
