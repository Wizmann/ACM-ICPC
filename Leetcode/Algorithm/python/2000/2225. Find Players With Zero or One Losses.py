from collections import defaultdict

class Solution(object):
    def findWinners(self, matches):
        win = defaultdict(int)
        lose = defaultdict(int)
        players = set()
        
        for (a, b) in matches:
            win[a] += 1
            lose[b] += 1
            players.add(a)
            players.add(b)
            
        no_loss = []
        one_loss = []
        for player in players:
            if lose[player] == 0:
                no_loss.append(player)
            if lose[player] == 1:
                one_loss.append(player)
        no_loss.sort()
        one_loss.sort()
        return [ no_loss, one_loss ]
