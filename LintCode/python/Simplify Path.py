class Solution:
    # @param {string} path the original path
    # @return {string} the simplified path
    def simplifyPath(self, path):
        path = filter(lambda x: x,
                path.split('/'))
                
        res = []
        for item in path:
            if item == '.':
                continue
            if item == '..':
                if res:
                    res.pop()
                continue
            res.append(item)
            
        return '/' + '/'.join(res)
