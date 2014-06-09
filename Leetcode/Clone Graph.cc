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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        map<int, UndirectedGraphNode*> mp;
        set<int> visited;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        while (!q.empty()) {
            UndirectedGraphNode* now = q.front();
            q.pop();
            
            if (visited.find(now -> label) != visited.end()) {
                continue;
            } else {
                visited.insert(now -> label);
            }
            
            UndirectedGraphNode* cl = NULL;
            if (mp.find(now -> label) == mp.end()) {
                mp[now -> label] = new UndirectedGraphNode(now -> label);
            }
            
            cl = mp[now -> label];
            for (auto iter = (now -> neighbors).begin(); 
                    iter != (now -> neighbors).end(); 
                    ++iter) {
                UndirectedGraphNode* next = *iter;
                if (mp.find(next -> label) == mp.end()) {
                    mp[next -> label] = new UndirectedGraphNode(next -> label);
                }
                (cl -> neighbors).push_back(mp[next -> label]);
                q.push(next);
            }
        }
        return mp[node -> label];
    }
};
