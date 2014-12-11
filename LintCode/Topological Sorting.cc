/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        unordered_map<DirectedGraphNode*, int> in;
        for (auto node: graph) {
            for (auto neighbor: node->neighbors) {
                in[neighbor]++;
            }
        }
        vector<DirectedGraphNode*> res;
        queue<DirectedGraphNode*> q;
        
        for (auto cur: graph) {
            if (in[cur] == 0) {
                q.push(cur);
            }
        }
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            res.push_back(cur);
            
            for (auto node: cur->neighbors) {
                in[node]--;
                if (in[node] == 0) {
                    q.push(node);
                }
            }
        }
        
        return res;
    }
};
