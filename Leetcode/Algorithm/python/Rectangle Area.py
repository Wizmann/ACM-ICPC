class Solution:
    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @param {integer} E
    # @param {integer} F
    # @param {integer} G
    # @param {integer} H
    # @return {integer}
    def computeArea(self, A, B, C, D, E, F, G, H):
        delta_x = max(0, min(C, G) - max(A, E))
        delta_y = max(0, min(D, H) - max(B, F))
        
        u = delta_x * delta_y
        
        return abs(A - C) * abs(B - D) + abs(E - G) * abs(F - H) - u
        
