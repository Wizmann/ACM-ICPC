class Solution(object):
    def predictPartyVictory(self, senate):
        sr = map(lambda x: x[0], filter(lambda y: y[1] == 'R', enumerate(senate)))
        sd = map(lambda x: x[0], filter(lambda y: y[1] == 'D', enumerate(senate)))
        
        sr, sd = self.solve(sr, sd, len(senate))
            
        if sr:
            return 'Radiant'
        else:
            return 'Dire'
        
    def solve(self, sr, sd, n):
        while sr and sd:
            if sr[0] < sd[0]:
                del sd[0]
                sr.append(sr[0] + n)
                del sr[0]
            else:
                del sr[0]
                sd.append(sd[0] + n)
                del sd[0]
        return sr, sd
