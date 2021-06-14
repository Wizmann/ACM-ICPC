class Solution(object):
    def maximumBinaryString(self, binary):
        binary = map(int, binary)
        n = len(binary)
        
        ptr = 0
        while ptr < n and binary[ptr] == 1:
            ptr += 1
            
        res = '1' * ptr
        if ptr == n:
            return res
        
        m = n - ptr
        ones = binary[-m:].count(1)

        return (res + '1' * (m - ones - 1) + '0' + '1' * ones)[-n:]
