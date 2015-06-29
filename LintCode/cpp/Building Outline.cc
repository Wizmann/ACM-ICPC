struct Line {
    int height;
    int status;
};

class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        map<int, vector<Line> > mp;
        for (auto& building: buildings) {
            auto start  = building[0];
            auto end    = building[1];
            auto height = building[2];
            
            auto iter1 = mp.find(start);
            if (iter1 == mp.end()) {
                mp[start] = vector<Line>();
            }
            mp[start].push_back({height, 1});
            
            auto iter2 = mp.find(end);
            if (iter2 == mp.end()) {
                mp[end] = vector<Line>();
            }
            mp[end].push_back({height, -1});
        }
        
        vector<vector<int> > res;
        multiset<int> st;
        int pre_x = 0;
        int pre_y = 0;
        for (auto& p: mp) {
            auto  cur_x  = p.first;
            auto& points = p.second;
            
            for (auto& point: points) {
                auto height = point.height;
                auto status = point.status;
                
                if (status == 1) {
                    st.insert(height);
                } else {
                    auto iter = st.find(height);
                    st.erase(iter);
                }
            }
            
            int cur_y = 0;
            if (!st.empty()) {
                cur_y = *st.rbegin();
            }
            if (pre_y != cur_y) {
                if (pre_y != 0) {
                    res.push_back({pre_x, cur_x, pre_y});
                }
                pre_x = cur_x;
            }
            pre_y = cur_y;
        }
        return res;
    }
};
