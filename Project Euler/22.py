names = [name for name in open("names.txt").read().split(",")]
names = map(lambda x: x.replace("\"", ""), names)
names.sort()

for item in names:
    print item


ans = 0
for i, name in enumerate(names):
    name = map(lambda x: ord(x) - ord('A') + 1, name)
    s = sum(name) * (i + 1)
    ans += s

print ans
