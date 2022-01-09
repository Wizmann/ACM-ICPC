class Solution(object):
    def restoreString(self, s, indices):
        return ''.join(map(lambda (idx, c): c, sorted(zip(indices, s))))
