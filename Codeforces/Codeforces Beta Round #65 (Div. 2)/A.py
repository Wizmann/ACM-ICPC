n = int(raw_input())
for i in xrange(n):
    word = raw_input().strip()
    if len(word) > 10:
        word = ''.join([word[0], str(len(word) - 2), word[-1]])
    print word
