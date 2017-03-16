d = {
'Tetrahedron': 4,
'Cube': 6,
'Octahedron': 8,
'Dodecahedron': 12,
'Icosahedron': 20,
}

if __name__ == '__main__':
    T = int(raw_input())
    ans = 0
    for i in xrange(T):
        item = raw_input().strip()
        ans += d[item]
    print ans
