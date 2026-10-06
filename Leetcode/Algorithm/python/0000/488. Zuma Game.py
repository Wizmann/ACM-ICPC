class Solution(object):
    def __init__(self):
        self.visit = set([])
        self.res = 10 ** 10
        
    def findMinStep(self, board, hand):
        hand = sorted(hand)
        board = list(board)
        st = [(board, hand, 0)]
        while st:
            board, hand, step = st.pop()
            if step > self.res:
                continue
            
            for i in xrange(len(hand)):
                if i and hand[i - 1] == hand[i]:
                    continue
                for j in xrange(len(board)):
                    if j and board[j - 1] == board[j]:
                        continue
                    if board[j] == hand[i]:
                        nboard = board[:j] + [hand[i]] + board[j:]
                        nhand = hand[:]
                        del(nhand[i])
                        nboard = self.eliminate(nboard)
                        
                        if nboard == []:
                            self.res = min(self.res, step + 1)
                        else:
                            st.append((nboard, nhand, step + 1))
                            
        return -1 if self.res >= 10 ** 10 else self.res
    
    def eliminate(self, board):
        board.append('X')
        while True:
            flag = False
            l, r = 0, 0
            n = len(board)
            for i in xrange(len(board)):
                if i and board[i] == board[i - 1]:
                    r = i + 1
                elif board[i] != board[i - 1]:
                    if r - l >= 3:
                        board = board[:l] + board[r:]
                        flag = True
                        break
                    else:
                        l, r = i, i + 1
            if not flag:
                break
        return board[:-1]


