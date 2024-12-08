class Solution(object):
    def checkTwoChessboards(self, coordinate1, coordinate2):
        x1 = (ord(coordinate1[0]) - ord('a')) % 2
        y1 = int(coordinate1[1]) % 2
        x2 = (ord(coordinate2[0]) - ord('a')) % 2
        y2 = int(coordinate2[1]) % 2
        return ((x1 ^ x2) ^ (y1 ^ y2)) == 0
