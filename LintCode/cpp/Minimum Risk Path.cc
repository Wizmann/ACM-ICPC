const int INF = 0x3f3f3f3f;

struct Edge {
    int dest;
    int cost;
};

class Solution {
public:
    /**
     * @param n: maximum index of position.
     * @param m: the number of undirected edges.
     * @param x: 
     * @param y: 
     * @param w: 
     * @return: return the minimum risk value.
     */
    int getMinRiskValue(int n, int m, vector<int> &x, vector<int> &y, vector<int> &w) {
        g = vector<vector<Edge> >(n + 1);
        for (int i = 0; i < m; i++) {
            int a = x[i];
            int b = y[i];
            int c = w[i];
            
            g[a].push_back({ b, c });
            g[b].push_back({ a, c });
        }
        
        inq = vector<bool>(n + 1, false);
        risk = vector<int>(n + 1, INF);
        risk[0] = 0;
        
        queue<int> q;
        q.push(0);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            inq[cur] = false;
            
            for (const auto& edge: g[cur]) {
                int next = edge.dest;
                int cost = max(risk[cur], edge.cost);
                
                if (risk[next] > cost) {
                    risk[next] = cost;
                    if (!inq[next]) {
                        inq[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        
        return risk[n];
    }
private:
    vector<bool> inq;
    vector<vector<Edge> > g;
    vector<int> risk;
};
