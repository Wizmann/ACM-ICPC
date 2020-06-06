typedef long long llint;

const llint MOD = 0xdeadbeefcafeLL;

struct Node {
    vector<int> pos;
    int sum = 0;
    
    bool operator < (const Node& other) const {
        return sum > other.sum;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<Node> pq;
        unordered_set<llint> st;
        int n = mat.size();
        int m = mat[0].size();
        
        {
            Node first;
            for (int i = 0; i < n; i++) {
                first.pos.push_back(0);
                first.sum += mat[i][0];
            }
            pq.push(first);
        }
        
        int res = -1;
        while (st.size() < k) {
            llint h = 0;
            auto cur = pq.top();
            pq.pop();
            
            for (int j = 0; j < n; j++) {
                h = h * 41 + cur.pos[j] + 1;
                h %= MOD;
            }
            
            if (st.count(h)) {
                continue;
            }
            st.insert(h);
            
            res = cur.sum;
            // cout << res << endl;
            
            for (int j = 0; j < n; j++) {
                auto nxt = cur;
                if (nxt.pos[j] + 1 < m) {
                    nxt.sum -= mat[j][nxt.pos[j]];
                    nxt.sum += mat[j][++nxt.pos[j]];
                    pq.push(nxt);
                }
            }
        }
        return res;
    }
};
