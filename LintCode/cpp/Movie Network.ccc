class Solution {
public:
    /**
     * @param rating: the rating of the movies
     * @param G: the realtionship of movies
     * @param S: the begin movie
     * @param K: top K rating 
     * @return: the top k largest rating moive which contact with S
     */
    vector<int> topKMovie(
            vector<int> &rating, 
            vector<vector<int>> &G, 
            int S, 
            int K) {
        int n = rating.size();
        vector<bool> visit(n, false);
        queue<int> q;
        q.push(S);
        priority_queue<pair<int, int> > pq;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if (visit[cur]) {
                continue;
            }
            
            if (cur != S) {
                pq.push({rating[cur], cur});
            }
            
            visit[cur] = true;
            
            for (auto next: G[cur]) {
                q.push(next);
            }
        }
        
        vector<int> result;
        for (int i = 0; i < K && !pq.empty(); i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
