class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto stone: stones) {
            pq.push(stone);
        }
        
        while (pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            cout << a << ' ' << b << endl;
            if (a == b) {
                continue;
            }
            
            pq.push(abs(a - b));
        }
        
        if (pq.size() == 0) {
            return 0;
        }
        return pq.top();
    }
};
