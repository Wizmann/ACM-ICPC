from collections import Counter

class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        c = Counter(magazine)
        c.subtract(ransomNote)
        return all(map(lambda (key, value): value >= 0, c.items())) 
        
