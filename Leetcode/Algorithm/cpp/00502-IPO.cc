struct Action {
    int profit;
    int capital;
    
    bool operator < (const Action& a) const {
        return (profit) < (a.profit);
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<Action> pq;
        vector<Action> actions;
        
        int n = Profits.size();
        for (int i = 0; i < n; i++) {
            actions.push_back({Profits[i], Capital[i]});
        }
        sort(actions.begin(), actions.end(), [](const Action& aa, const Action& ab) {
            return aa.capital < ab.capital;
        });
        
        int ptr = 0;
        
        for (int i = 0; i < k; i++) {
            while (ptr < n && actions[ptr].capital <= W) {
                if (actions[ptr].profit > 0) {
                    pq.push(actions[ptr]);
                }
                ptr++;
            }
            if (pq.empty()) {
                continue;
            }
            auto cur = pq.top();
            pq.pop();
            //cout << cur.capital << ' ' << cur.profit << endl;
            W += cur.profit;
        }
        return W;
    }
};
