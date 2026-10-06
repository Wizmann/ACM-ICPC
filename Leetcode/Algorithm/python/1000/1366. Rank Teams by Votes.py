# https://leetcode.com/problems/rank-teams-by-votes/

from typing import *

class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        assert votes
        teams = list(votes[0])
        m = len(teams)
        d = {}
        for team in teams:
            d[team] = [0 for i in range(m)] + [-ord(team)]

        for vote in votes:
            for i, c in enumerate(vote):
                d[c][i] += 1
        res = ''
        for (k, v) in sorted(d.items(), key=lambda kv: kv[1], reverse=True):
            res += k
        return res

S = Solution()
assert S.rankTeams(["ABC","ACB","ABC","ACB","ACB"]) == 'ACB'
assert S.rankTeams(["WXYZ","XYZW"]) == 'XWYZ'
assert S.rankTeams(["ABC"]) == 'ABC'
assert S.rankTeams(["A", "A"]) == 'A'
assert S.rankTeams(["AB", "BA"]) == 'AB'
assert S.rankTeams(["BCA","CAB","CBA","ABC","ACB","BAC"]) == 'ABC'
