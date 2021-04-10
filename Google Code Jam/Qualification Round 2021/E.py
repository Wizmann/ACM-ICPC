INF = 10 ** 10
N = 100
M = 10000
K = 300

def solve(ppl):
    difficulty = [0 for i in xrange(M)]
    skill = [0 for i in xrange(N)]
    for i, p in enumerate(ppl):
        for j, c in enumerate(p):
            difficulty[j] += int(c)
            skill[i] += int(c)
        skill[i] /= 1.0 * M
    skill = sorted(zip(skill, range(N)))
    difficulty = sorted(zip(difficulty, range(M)))
    hard_problems = []
    easy_problems = []

    for i in xrange(K):
        hard_problems.append(difficulty[i][1])
    for i in xrange(K):
        easy_problems.append(difficulty[M - 1 - i][1])

    correctness_hard = [0 for i in xrange(N)]
    for i, p in enumerate(ppl):
        cnt = 0
        for nr in hard_problems:
            if p[nr] == '1':
                cnt += 1
        correctness_hard[i] = 1.0 * cnt / K

    correctness_easy = [0 for i in xrange(N)]
    for i, p in enumerate(ppl):
        cnt = 0
        for nr in easy_problems:
            if p[nr] == '1':
                cnt += 1
        correctness_easy[i] = 1.0 * cnt / K

    candidates = []
    for i, p in enumerate(correctness_hard):
        candidates.append((p, i))
    candidates = map(lambda (p, i): i, sorted(candidates, reverse=True))[:20]
    # print candidates[:20]
    # print skill

    maxi = -INF
    maxp = -1
    for i, (s1, idx1) in enumerate(skill):
        h1 = correctness_hard[idx1]
        # print s1, idx1, 1.0 * h1 / s1
        if s1 < 0.3 or s1 > 0.9:
            continue
        if i - 1 >= 0:
            s0, idx0 = skill[i - 1]
            h0 = correctness_hard[idx0]

            u = 1.0 * h1 / s1 - 1.0 * h0 / s0
            if u > maxp:
                maxi = idx1
                maxp = u
        if i + 1 < N:
            s2, idx2 = skill[i + 1]
            h2 = correctness_hard[idx2]

            u = 1.0 * h1 / s1 - 1.0 * h2 / s2
            if u > maxp:
                maxi = idx1
                maxp = u
    return maxi + 1 

T = int(raw_input())
P = int(raw_input())

for case_ in xrange(T):
    ppl = []
    for i in xrange(N):
        ppl.append(raw_input().strip())

    res = solve(ppl)
    print 'Case #%d: %d' % (case_ + 1, res)



