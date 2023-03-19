choices = [len(raw_input()[2:]) for i in xrange(4)]

answers = []
for i in xrange(4):
    c, d = [], []
    for j in xrange(4):
        if i == j:
            continue
        a = choices[i]
        b = choices[j]
        if a >= 2 * b:
            c.append(j)
        if a <= b / 2:
            d.append(j)
    if len(c) == 3 or len(d) == 3:
        answers.append(chr(i + ord('A')))

if len(answers) == 1:
    print ''.join(answers)
else:
    print 'C'
