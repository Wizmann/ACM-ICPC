const int my[] = {1, 0, -1, 0};
const int mx[] = {0, 1, 0, -1};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int> > st;
        
        for (const auto& obstacle: obstacles) {
            st.insert({obstacle[1], obstacle[0]});
        }
        int dir = 0;
        int y = 0;
        int x = 0;
        int ans = 0;
        for (auto cmd: commands) {
            switch (cmd) {
                case -1:
                    dir = (dir + 1) % 4;
                    break;
                case -2:
                    dir = (dir + 3) % 4;
                    break;
                default:
                    for (int i = 0; i < cmd; i++) {
                        int ny = y + my[dir];
                        int nx = x + mx[dir];
                        
                        if (st.count({ny, nx})) {
                            break;
                        } else {
                            y = ny;
                            x = nx;
                        }
                        ans = max(ans, y * y + x * x);
                    }
            }
        }
        return ans;
    }
};
