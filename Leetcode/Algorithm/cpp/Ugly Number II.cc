class Solution {
    typedef long long llint;
    struct Node {
        llint a, b, c;
        llint mul() const {
            return a * b * c;
        }
    };
public:
    int nthUglyNumber(int n) {
        priority_queue<Node, vector<Node>, function<bool(const Node&, const Node&)> > pq(
            [](const Node& x, const Node& y) {
                return x.mul() > y.mul();
            });
            
        pq.push({1, 1, 1});
        Node cur;
        llint pre = -1;
        for (int i = 0; i < n; /* pass */) {
            cur = pq.top();
            pq.pop();
            if (cur.mul() == pre) {
                continue;
            }
            pre = cur.mul();
            
            {
                Node next2 = cur;
                next2.a *= 2;
                pq.push(next2);
            }
            {
                Node next3 = cur;
                next3.b *= 3;
                pq.push(next3);
            }
            {
                Node next5 = cur;
                next5.c *= 5;
                pq.push(next5);
            }
            i++;
        }
        return cur.mul();
    }
};
