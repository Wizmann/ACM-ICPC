class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> AB = get_map(A, B);
        unordered_map<int, int> CD = get_map(C, D);
        
        int ans = 0;
        for (auto p: AB) {
            int u = -p.first;
            int cnt = p.second;
            if (CD.find(u) != CD.end()) {
                ans += 1LL * cnt * CD[u];
            }
        }
        return ans;
    }
private:
    unordered_map<int, int> get_map(const vector<int>& A, const vector<int>& B) {
        unordered_map<int, int> res;
        for (auto a: A) {
            for (auto b: B) {
                res[a + b]++;
            }
        }
        return res;
    }
};
