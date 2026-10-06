class Solution(object):
    def isWinner(self, player1, player2):
        n = len(player1)
        assert n == len(player2)
        score1 = self.get_score(player1)            
        score2 = self.get_score(player2)
        
        if score1 == score2:
            return 0
        elif score1 > score2:
            return 1
        else:
            return 2
        
    def get_score(self, player):
        n = len(player)
        score = 0
        for i in xrange(n):
            maxi = 0
            if i - 2 >= 0:
                maxi = max(maxi, player[i - 2])
            if i - 1 >= 0:
                maxi = max(maxi, player[i - 1])
            if maxi == 10:
                score += player[i] * 2
            else:
                score += player[i]
        return score
            
        
