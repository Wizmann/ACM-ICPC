class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        g.resize(numCourses);
        in_degree.resize(numCourses);
        out_degree.resize(numCourses);
        
        for (auto& course_list: prerequisites) {
            int m = course_list.size();
            for (int i = 1; i < m; i++) {
                int a = course_list[i - 1];
                int b = course_list[i];
                
                add_edge(a, b);
            }
        }
        
        return top_sort();
    }
private:
    void add_edge(int a, int b) {
        g[a].push_back(b);
        in_degree[b]++;
        out_degree[a]++;
    }
    
    bool top_sort() {
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(auto next: g[cur]) {
                in_degree[next]--;
                if (in_degree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        int cnt = 0;
        for (auto i: in_degree) {
            if (i == 0) {
                cnt++;
            }
        }
        return cnt == n;
    }
private:
    int n;
    vector<vector<int> > g;
    vector<int> in_degree;
    vector<int> out_degree;
};
