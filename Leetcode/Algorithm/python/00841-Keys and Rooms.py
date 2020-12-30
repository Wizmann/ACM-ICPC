class Solution(object):
    def canVisitAllRooms(self, rooms):
        visited = set([0])
        st = [0]
        while st:
            cur = st.pop()
            visited.add(cur)
            for r in rooms[cur]:
                if r in visited:
                    continue
                st.append(r)
        return len(rooms) == len(visited)
            
        
