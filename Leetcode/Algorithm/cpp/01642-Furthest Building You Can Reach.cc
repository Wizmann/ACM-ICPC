typedef long long llint;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int> > pq;
        int sum = 0;
        int n = heights.size();
        
        for (int i = 1; i < n; i++) {
            int delta = heights[i] - heights[i - 1];
            if (delta <= 0) {
                continue;
            }
            pq.push(delta);
            while (pq.size() > ladders) {
                sum += pq.top();
                pq.pop();
            }
            
            if (sum > bricks) {
                return i - 1;
            }
        }
        return n - 1;
    }
};
