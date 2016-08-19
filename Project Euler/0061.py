import itertools
def get_index(fun):
    d = {}
    i = 0
    while fun(i) < 10000:
        s = str(fun(i))
        i += 1
        if len(s) < 4:
            continue
        assert len(s) == 4
        l, r = s[:2], s[2:]
        d[l] = d.get(l, [])
        d[l].append(r)
    return d

fs = [
        lambda x: x,
        lambda x: x,
        lambda x: x,
        lambda x: x * (x + 1) / 2,
        lambda x: x * x,
        lambda x: x * (3 * x - 1) / 2,
        lambda x: x * (2 * x - 1),
        lambda x: x * (5 * x - 3) / 2,
        lambda x: x * (3 * x - 2),
]




ds = []

def run():
    res = []
    def dfs(cur, prefix):
        next = cur + 1

        #print res
        if cur == 9 and len(res) == 6:
            if res[0][:2] == res[-1][2:]:
                print res
                print sum(map(int, res))
            return

        if cur == 9:
            return

        for item in ds[cur].get(prefix, []):
            res.append(prefix + item)
            dfs(next, item)
            res.pop()

    for key, values in ds[3].items():
        for value in values:
            res.append(key + value)
            dfs(4, value)
            res.pop()

if __name__ == '__main__':
    for perm in itertools.permutations(range(3, 8 + 1)):
        ds = [{}, {}, {}] + [get_index(fs[i]) for i in perm]
        run()

