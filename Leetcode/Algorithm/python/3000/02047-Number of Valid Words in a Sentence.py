import re

class Solution(object):
    def countValidWords(self, sentence):
        cnt = 0
        for item in sentence.split():
            item = item.strip()
            if re.match(r"^(([a-z]*)|([a-z]+\-[a-z]+))[\,\!\.]?$", item):
                cnt += 1
        return cnt
