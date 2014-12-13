/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        _mp.clear();
        return dfs(node);
    }
private:
    UndirectedGraphNode *dfs(UndirectedGraphNode* node) {
        if (_mp.find(node) != _mp.end()) {
            return _mp[node];
        }
        UndirectedGraphNode* new_node = new UndirectedGraphNode(-1);
        _mp[node] = new_node;
        *new_node = *node;
        
        for (auto& neighbor: new_node->neighbors) {
            neighbor = dfs(neighbor);
        }
        return new_node;
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> _mp;
};
