class Codec:
    def __init__(self):
        self.db = []

    def encode(self, longUrl):
        self.db.append(longUrl)
        return '%x' % (len(self.db) - 1)
        

    def decode(self, shortUrl):
        idx = int(shortUrl, 16)
        return self.db[idx]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
