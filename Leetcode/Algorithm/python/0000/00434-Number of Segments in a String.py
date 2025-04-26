import re
class Solution(object):
    def countSegments(self, s):
        return len(re.findall('(\S+)', s))
