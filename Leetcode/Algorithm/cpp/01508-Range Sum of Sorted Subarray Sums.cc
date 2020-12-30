const int MOD = 1'000'000'000 + 7;

struct Node {
    int ptr;
    int tot;
    
    bool operator < (const Node& other) const {
        return tot > other.tot;
    }
};

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<Node> pq;
        for (int i = 0; i < n; i++) {
            pq.push({i, nums[i]});
        }
        int tot = 0;
        int idx = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int v = cur.tot;
            cur.ptr += 1;
            if (cur.ptr < n) {
                cur.tot += nums[cur.ptr];
                pq.push(cur);
            }
            idx++;
            if (left <= idx && idx <= right) {
                tot = (tot + v) % MOD;
            }
        }
        return tot;
    }
};
