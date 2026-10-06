class Codec:

    def encode(self, strs):
        return '\a'.join(map(lambda s: '\b' + s + '\b', strs))
        

    def decode(self, s):
        return map(lambda x: x[1: -1], filter(lambda y: y.startswith('\b'), s.split('\a')))
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
