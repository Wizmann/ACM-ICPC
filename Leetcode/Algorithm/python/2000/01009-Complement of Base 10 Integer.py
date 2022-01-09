class Solution(object):
    def bitwiseComplement(self, N):
        u = max(1, N)
        u |= u >> 1
        u |= u >> 2
        u |= u >> 4
        u |= u >> 8
        u |= u >> 16
        u |= u >> 32
        return N ^ u
        
