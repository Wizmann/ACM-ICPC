class Solution {
    typedef long long llint;
    
    struct Node {
        int value;
        int ptr;
        int key;
        
        bool operator > (const Node& node) const {
            return value > node.value;
        }
    };
    
public:
    llint nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        int ugly_nums[n] = {0};
        priority_queue<
                Node,
                vector<Node>,
                greater<Node> >pq;
        
        ugly_nums[0] = 1;
        for (int i = 0; i < k; i++) {
            pq.push({primes[i], 0, primes[i]});
        }
        
        int ptr = 1;
        while (ptr < n) {
            auto p = pq.top();
            while (pq.top().value == ugly_nums[ptr - 1]) {
                p = pq.top();
                p.ptr++;
                p.value = ugly_nums[p.ptr] * p.key;
                pq.push(p);
                pq.pop();
            }
            p = pq.top();
            ugly_nums[ptr++] = p.value;
            p.ptr++;
            p.value = ugly_nums[p.ptr] * p.key;
            pq.push(p);
            pq.pop();
        }
        return ugly_nums[n - 1];
    }
};
