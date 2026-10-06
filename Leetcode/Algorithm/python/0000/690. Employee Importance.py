"""
# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution(object):
    def getImportance(self, employees, id):
        d = {}
        for e in employees:
            d[e.id] = e
            
        st = [id]
        res = 0
        while st:
            cur = st.pop()
            res += d[cur].importance
            for sub in d[cur].subordinates:
                st.append(sub)
        return res
