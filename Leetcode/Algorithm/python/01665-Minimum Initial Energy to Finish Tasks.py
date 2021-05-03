class Solution(object):
    def minimumEffort(self, tasks):
        tasks.sort(key=lambda (a, m): (-m + a, m))
        mini = 0
        cur = 0

        for (actual, minimum) in tasks:
            if cur < minimum:
                delta = minimum - cur
                cur += delta
                mini += delta
            cur -= actual
            assert cur >= 0
        return mini
