my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        if image[sr][sc] == newColor:
            return image
        
        n = len(image)
        if n == 0:
            return []
        m = len(image[0])
        
        c = image[sr][sc]
        st = [(sr, sc)]
        while st:
            (y, x) = st.pop()
            if image[y][x] != c:
                continue
            image[y][x] = newColor
            for i in xrange(4):
                ny = y + my[i]
                nx = x + mx[i]
                if 0 <= ny < n and 0 <= nx < m and image[ny][nx] == c:
                    st.append((ny, nx))
        return image
