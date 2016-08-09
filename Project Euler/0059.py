import string

cipher = None
with open("cipher1.txt") as cipher_txt:
    cipher = map(int, cipher_txt.read().split(","))

GROUPS = 3
groups = [cipher[i::GROUPS] for i in xrange(GROUPS)]
stat = []

for group in groups:
    group = set(map(lambda x: (x, group.count(x)) ,group))
    maxi = max(group, key=lambda x: x[1])
    stat.append(maxi[0])

pwds = []
for c in string.lowercase + ' ':
    pwd = []
    for item in stat:
        pwd.append(chr(item ^ ord(c)))
    if all(map(lambda x: x in string.lowercase, pwd)):
        pwds.append(''.join(pwd))

for pwd in pwds:
    pwd = map(ord, pwd)
    ans = 0
    for i, c in enumerate(cipher):
        ans += c ^ pwd[i % GROUPS]
    print ans
