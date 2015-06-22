class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        int n = matrix.size();
        if (n == 0) {
            return -1;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return -1;
        }
        
        priority_queue<
                pair<int, int>, 
                vector<pair<int, int> >,
                std::function<bool(pair<int, int>, pair<int, int>)>
        > pq([&matrix](pair<int, int> pa, pair<int, int> pb) {
            return matrix[pa.first][pa.second] > matrix[pb.first][pb.second];
        });
        
        for (int i = 0; i < n; i++) {
            pq.push({i, 0});
        }
        
        for (int i = 0; i < k - 1; i++) {
            auto p = pq.top();
            pq.pop();
            
            int y = p.first;
            int x = p.second;
            
            if (x + 1 < m) {
                pq.push({y, x + 1});
            }
        }
        return matrix[pq.top().first][pq.top().second];
    }
};
