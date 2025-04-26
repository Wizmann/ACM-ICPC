META = "META"

class Trie(object):
    def __init__(self):
        self.root = {}

    def insert(self, word, idx):
        self.do_insert(self.root, 0, word[::-1], idx)

    def do_insert(self, root, cur, word, idx):
        if META not in root:
            root[META] = (word, idx)
        else:
            if len(word) < len(root[META][0]):
                root[META] = (word, idx)

        if cur == len(word):
            return

        c = word[cur]
        if c not in root:
            root[c] = {}
        nxt = root[c]
        self.do_insert(nxt, cur + 1, word, idx)

    def query(self, word):
        return self.do_query(self.root, 0, word[::-1])

    def do_query(self, root, cur, word):
        if cur == len(word):
            return root[META][1]
        c = word[cur]
        if c not in root:
            return root[META][1]
        return self.do_query(root[c], cur + 1, word)

class Solution(object):
    def stringIndices(self, wordsContainer, wordsQuery):
        trie = Trie()
        for i, w in enumerate(wordsContainer):
            trie.insert(w, i)
        res = []
        for w in wordsQuery:
            res.append(trie.query(w))
        return res

