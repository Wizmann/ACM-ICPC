const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int n = nuts.size();
        if (n == 0) {
            return -1;
        }
        vector<int> dis1(n);
        vector<int> dis2(n);
        
        int sy = squirrel[0];
        int sx = squirrel[1];
        
        int ty = tree[0];
        int tx = tree[1];
        
        int st = 0;
        
        for (int i = 0; i < n; i++) {
            auto nut = nuts[i];
            int ny = nut[0];
            int nx = nut[1];
            
            dis1[i] = abs(sy - ny) + abs(sx - nx);
            dis2[i] = abs(ty - ny) + abs(tx - nx);
            
            st += dis2[i];
        }
        
        int ans = INF;
        for (int i = 0; i < n; i++) {
            int cur = dis1[i] + dis2[i] + (st - dis2[i]) * 2;
            ans = min(ans, cur);
        }
        return ans;
    }
};
