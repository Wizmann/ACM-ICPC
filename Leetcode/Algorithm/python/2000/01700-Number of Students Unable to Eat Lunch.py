class Solution(object):
    def countStudents(self, students, sandwiches):
        n = len(students)
        m = len(sandwiches)
        pm = 0
        while pm < m:
            pm_pre = pm
            for i in xrange(n):
                cur = students[i]
                if cur == -1:
                    continue
                if cur == sandwiches[pm]:
                    students[i] = -1
                    pm += 1
            if pm == pm_pre:
                break
        return m - pm
