class Compare
{
public:
    bool operator() (const pair<int, int>& pa, const pair<int, int>& pb) {
        int a = pa.first * pb.second;
        int b = pb.first * pa.second;

        return a < b;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = A.size();
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> fractions;
        
        auto cmp = Compare();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pair<int, int> cur = {A[i], A[j]};
                if (fractions.size() < K || cmp(cur, fractions.top())) {
                    fractions.push({A[i], A[j]});
                }
                
                while (fractions.size() > K) {
                    fractions.pop();
                }
            }
        }
        auto res = fractions.top();
        return vector<int>({res.first, res.second});
    }
};
