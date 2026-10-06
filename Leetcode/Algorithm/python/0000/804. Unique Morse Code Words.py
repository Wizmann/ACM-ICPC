class Solution(object):
    def uniqueMorseRepresentations(self, words):
        code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        
        s = set()
        
        for word in words:
            u = ''.join(map(lambda c: code[ord(c) - ord('a')], word))
            s.add(u)
            
        return len(s)
