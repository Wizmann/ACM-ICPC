from collections import defaultdict

c_inconsistency = 'Inconsistency'
c_undetermined = 'Undetermined'
c_sorted = 'Sorted'

(n, m) = map(int, raw_input().split())
relations = []
idx = 0

def get_idx(c):
    return ord(c) - ord('A')

for i in xrange(m):
    s = raw_input().strip()
    l, r = s[0], s[-1]
    l = get_idx(l)
    r = get_idx(r)
    relations.append((l, r))

def check(rels):
    g = defaultdict(list)
    ind = [0 for i in xrange(n)]
    for (a, b) in rels:
        g[a].append(b)
        ind[b] += 1

    undetermined = 0
    inconsistency = 0
    order = []
    # print rels
    while len(order) < n:
        # print order
        level = []
        for i in xrange(n):
            if ind[i] == 0:
                level.append(i)
                ind[i] = -1
        # print 'level', level

        # print level
        if len(level) == 1:
            order.append(chr(level[0] + ord('A')))
        elif len(level) > 1:
            undetermined = True
            for cur in level:
                order.append(chr(cur + ord('A')))
        elif len(level) == 0:
            inconsistency = True
            break
        else:
            assert False

        for cur in level:
            for nxt in g[cur]:
                ind[nxt] -= 1
    # print inconsistency, undetermined

    if inconsistency:
        return c_inconsistency, ""
    elif undetermined:
        return c_undetermined, ""
    else:
        return c_sorted, ''.join(order)


for i in xrange(m):
    flag, res = check(relations[:i + 1])

    if flag == c_inconsistency:
        print 'Inconsistency found after %d relations.' % (i + 1)
        break
    elif flag == c_sorted:
        print 'Sorted sequence determined after %d relations: %s.' % (i + 1, res)
        break
else:
    print 'Sorted sequence cannot be determined.'



'''
^^^TEST^^^
4 6
A<B
A<C
B<C
C<D
B<D
A<B
---
Sorted sequence determined after 4 relations: ABCD.
$$$TEST$$$

^^^TEST^^^
1 1
A<A
---
Inconsistency found after 1 relations.
$$$TEST$$$

^^^TEST^^^
3 4
A<B
C<B
A<C
C<A
---
Sorted sequence determined after 3 relations: ACB.
$$$TEST$$$

^^^TEST^^^
3 4
A<B
C<B
A<A
A<C
C<A
---
Inconsistency found after 3 relations.
$$$TEST$$$


^^^TEST^^^
3 2
A<B
A<B
---
Sorted sequence cannot be determined.
$$$TEST$$$

^^^TEST^^^
3 3
A<B
C<A
B<C
---
Sorted sequence determined after 2 relations: CAB.
$$$TEST$$$


^^^TEST^^^
3 2
A<B
C<B
---
Sorted sequence cannot be determined.
$$$TEST$$$


^^^TEST^^^
3 2
A<B
B<A
---
Inconsistency found after 2 relations.
$$$TEST$$$


^^^TEST^^^
26 1
A<Z
---
Sorted sequence cannot be determined.
$$$TEST$$$

^^^TEST^^^
6 6
A<F
B<D
C<E
F<D
D<E
E<F
---
Inconsistency found after 6 relations.
$$$TEST$$$

^^^TEST^^^
5 5
A<B
B<C
C<D
D<E
E<A
---
Sorted sequence determined after 4 relations: ABCDE.
$$$TEST$$$
'''
