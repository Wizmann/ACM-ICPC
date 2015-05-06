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
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        queue<DirectedGraphNode*> q;
        unordered_set<DirectedGraphNode*> visit;
        
        q.push(s);
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            if (visit.find(node) != visit.end()) {
                continue;
            }
            
            visit.insert(node);
            
            if (node->label == t->label) {
                return true;
            }
            
            for (auto neighbor: node->neighbors) {
                if (visit.find(neighbor) != visit.end()) {
                    continue;
                }
                q.push(neighbor);
            }
        }
        return false;
    }
};


