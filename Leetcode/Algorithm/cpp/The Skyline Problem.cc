struct Node {
    int pos;
    int height;
    int status;
};

function<int(const Node&, const Node&)> node_cmp = [](const Node& a, const Node& b) {
    if (a.pos != b.pos) {
        return a.pos < b.pos;
    }
    return a.height * a.status > b.height * b.status;
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Node> nodes;
        for (auto building: buildings) {
            nodes.push_back({
                building[0],
                building[2],
                1
            });
            nodes.push_back({
                building[1],
                building[2],
                -1
            });
        }
        sort(nodes.begin(), nodes.end(), node_cmp);
        
        multiset<int> mst;
        vector<pair<int, int> > ans;
        int pre_h = -1;
        int pre_x = -1;
        for (auto node: nodes) {
            if (node.status == 1) {
                if (node.height > pre_h) {
                    pre_x = node.pos;
                    pre_h = node.height;
                    ans.push_back({pre_x, pre_h});
                }
                mst.insert(node.height);
            } else {
                int u = node.height;
                mst.erase(mst.find(u));
                if (mst.empty()) {
                    ans.push_back({node.pos, 0});
                } else if (*mst.rbegin() < pre_h) {
                    pre_h = *mst.rbegin();
                    pre_x = node.pos;
                    ans.push_back({pre_x, pre_h});
                }
            }
        }
        return ans;
    }
};
