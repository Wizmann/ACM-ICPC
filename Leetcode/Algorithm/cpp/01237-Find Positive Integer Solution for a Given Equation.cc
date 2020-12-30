/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        ans.clear();
        dfs(cf, 1, 1, z);
        return ans;
    }
private:
    void dfs(CustomFunction& cf, int x, int y, int z) {
        if (visited.count({x, y}) != 0) {
            return;
        }
        visited.insert({x, y});
        int f = cf.f(x, y);
        if (f == z) {
            ans.push_back({x, y});
            return;
        } else if (f < z) {
            dfs(cf, x + 1, y, z);
            dfs(cf, x, y + 1, z);
        }
    }
private:
    vector<vector<int> > ans;
    set<vector<int> > visited;
};
