class Solution(object):
    def removeComments(self, source):
        s = '\n'.join(source)
        res = ''
        
        n = len(s)
        ptr = 0
        
        while ptr < n:
            if s[ptr: ptr + 2] == '//':
                while ptr < n and s[ptr] != '\n':
                    ptr += 1
            elif s[ptr: ptr + 2] == '/*':
                ptr += 2
                while ptr + 1 < n and s[ptr: ptr + 2] != '*/':
                    ptr += 1
                ptr += 2
            else:
                res += s[ptr]
                ptr += 1
        return filter(lambda x: x, res.split("\n"))
            
