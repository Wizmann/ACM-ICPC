// https://leetcode.com/problems/spiral-matrix/submissions/

const INF int = 0x3f3f3f3f

func spiralOrder(matrix [][]int) []int {
    var res []int
    
    n := len(matrix)
    if n == 0 {
        return res
    }
    m := len(matrix[0])
    
    y := 0
    x := 0
    dir := 0
    
    my := [4]int {0, 1, 0, -1}
    mx := [4]int {1, 0, -1, 0}
     
    for i := 0; i < n * m; i++ {
        res = append(res, matrix[y][x])
        matrix[y][x] = -INF
        for i < n * m - 1 {
            ny := y + my[dir]
            nx := x + mx[dir]

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || matrix[ny][nx] == -INF) {
                dir = (dir + 1) % 4
            } else {
                y = ny
                x = nx
                break
            }
        }
    }
    return res
}
