typedef long long llint;

struct Candidate {
    int cost;
    int index;
    
    bool operator > (const Candidate& other) const {
        if (cost != other.cost) {
            return cost > other.cost;
        }
        return index > other.index;
    }
};

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<Candidate, vector<Candidate>, greater<Candidate> > pq;
        llint res = 0;
        int n = costs.size();
        
        int p = min(n - 1, candidates - 1);
        int q = max(0, n - candidates);
        if (q <= p) {
            for (int i = 0; i < n; i++) {
                pq.push({costs[i], i});
            }
        } else {
            for (int i = 0; i <= p; i++) {
                pq.push({costs[i], i});
            }
            for (int i = n - 1; i >= q; i--) {
                pq.push({costs[i], i});
            }
        }
        while (k--) {
            auto c = pq.top();
            pq.pop();
            res += c.cost;
            
            // cout << c.cost << ' ' << c.index << ' ' << p << ' ' << q << endl;
            
            if (q <= p) {
                continue;
            }
            
            if (c.index <= p) {
                p++;
                if (p < q)
                {
                    pq.push({costs[p], p});
                }
            } else {
                q--;
                if (p < q)
                {
                    pq.push({costs[q], q});
                }
            }
        }
        
        return res;
    }
};
