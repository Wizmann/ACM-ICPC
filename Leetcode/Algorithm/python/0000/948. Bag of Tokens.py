class Solution(object):
    def bagOfTokensScore(self, tokens, P):
        res = 0
        
        tokens.sort()
        
        score = 0
        while tokens:
            if P >= tokens[0]:
                score += 1
                P -= tokens[0]
                res = max(res, score)
                tokens.pop(0)
            elif score:
                score -= 1
                P += tokens[-1]
                tokens.pop()
            else:
                break
        return res
                
