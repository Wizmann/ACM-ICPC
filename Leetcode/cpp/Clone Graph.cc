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
    typedef UndirectedGraphNode Node;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return nullptr;
        }
        mp.clear();
        return dfs(node);
    }
private:
    Node* dfs(Node* node) {
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }
        
        Node* _node = new Node(-1);
        *_node = *node;
        mp[node] = _node;
        
        for (auto& neighbor: _node->neighbors) {
            neighbor = dfs(neighbor);
        }
        return _node;
    }
private:
    unordered_map<Node*, Node*> mp;
};
