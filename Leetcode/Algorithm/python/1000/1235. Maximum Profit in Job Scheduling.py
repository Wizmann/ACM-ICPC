class Solution(object):
    def jobScheduling(self, startTime, endTime, profit):
        n = len(startTime)
        
        jobs = []
        for i in xrange(n):
            st = startTime[i]
            end = endTime[i]
            p = profit[i]
            
            jobs.append((st, end, p))
            
        jobs.sort(key=lambda job: job[1])
        
        st = [(0, 0)]
        
        for job in jobs:
            l, r = 0, len(st) - 1
            pst = job[0]
            while l <= r:
                m = (l + r) / 2
                if st[m][0] > pst:
                    r = m - 1
                else:
                    l = m + 1
            idx = r
            # print st, pst, st[idx]
            value = st[idx][1]
            value += job[2]
            if st:
                (p0, v0) = st[-1]
                (p1, v1) = job[1], value
                
                if v1 > v0:
                    st.append((p1, v1))
        
        return st[-1][1]
