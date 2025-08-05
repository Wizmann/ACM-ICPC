class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int cnt = 0;
        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                for (const auto& circle : circles) {
                    int dy = i - circle[0];
                    int dx = j - circle[1];
                    int r = circle[2];
                    
                    if (dy * dy + dx * dx <= r * r) {
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};
