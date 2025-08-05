class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph_) {
        n = graph_.size();
        visit = vector<bool>(n, false);
        graph = graph_;
        
        dfs(0, n - 1);;
        
        return res;
    }
private:
    void dfs(int cur, int end) {
        if (cur == end) {
            buffer.push_back(cur);
            res.push_back(buffer);
            buffer.pop_back();
            return;
        }
        
        visit[cur] = true;
        buffer.push_back(cur);
        for (auto next: graph[cur]) {
            if (visit[next]) {
                continue;
            }
            dfs(next, end);
        }
        visit[cur] = false;
        buffer.pop_back();
    }
private:
    int n;
    vector<bool> visit;
    vector<int> buffer;
    vector<vector<int> > res;
    vector<vector<int> > graph;
};
