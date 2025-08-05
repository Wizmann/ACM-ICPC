typedef long long llint;

struct Node {
    int v1, p1, v2, p2;
    
    bool operator > (const Node& other) const {
        return GetValue() > other.GetValue();
    }

    llint GetValue() const {
        llint vv1 = 1;
        llint vv2 = 1;
        for (int i = 0; i < p1; i++) {
            vv1 *= v1;
        }
        for (int i = 0; i < p2; i++) {
            vv2 *= v2;
        }
        return vv1 + vv2;
    }
};

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        priority_queue<Node, vector<Node>, greater<Node> > pq;
        pq.push({x, 0, y, 0});
        vector<int> res;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            llint value = cur.GetValue();
            if (value > bound) {
                break;
            }
            if (!res.empty() && value == *res.rbegin()) {
                // pass
            } else {
                res.push_back(value);
            }
            if (cur.v1 != 1) pq.push({cur.v1, cur.p1 + 1, cur.v2, cur.p2});
            if (cur.v2 != 1) pq.push({cur.v1, cur.p1, cur.v2, cur.p2 + 1});
        }
        return res;
    }
};
