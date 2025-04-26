from collections import defaultdict

class Encrypter(object):

    def __init__(self, keys, values, dictionary):
        self.d = dict(zip(keys, values))
        self.C = defaultdict(int)
        for word in dictionary:
            encrypted = self.encrypt(word)
            self.C[encrypted] += 1
        

    def encrypt(self, word1):
        res = ''
        for c in word1:
            if c in self.d:
                res += self.d[c]
            else:
                return ''
        return res
        

    def decrypt(self, word2):
        return self.C.get(word2, 0)
        


# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)
