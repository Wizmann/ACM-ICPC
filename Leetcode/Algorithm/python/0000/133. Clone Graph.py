# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    def __init__(self):
        self.d = {}
    
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if not node:
            return node
        if node.label in self.d:
            return None
            
        new_node = UndirectedGraphNode(node.label)
        self.d[node.label] = new_node
        for neighbor in node.neighbors:
            self.cloneGraph(neighbor)
        new_node.neighbors = map(
            lambda x: self.d[x.label], node.neighbors)
        return new_node
        
