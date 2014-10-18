keys = list('qwertyuiop asdfghjkl; zxcvbnm,./')

dd = -1 if raw_input() == 'R' else +1
d = {}

for i, key in enumerate(keys):
    if i + dd >= 0 and i + dd < len(keys):
        d[key] = keys[i + dd]

print ''.join(map(lambda x: d[x], raw_input()))
