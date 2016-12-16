package main
import "fmt"

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func main() {
    const N int = 6
    const INF int = 0x3f3f3f3f
    mat := [N][N]int{}
    
    for i := 0; i < N; i++ {
        for j := 0; j < N; j++ {
            fmt.Scanf("%d", &mat[i][j])
        }
    }
    
    ans := -INF
    for i := 0; i < N; i++ {
        for j := 0; j < N; j++ {
            if i + 2 >= N || j + 2 >= N {
                continue
            }
            res := 0
            res += mat[i][j] + mat[i][j + 1] + mat[i][j + 2];
            res += mat[i + 1][j + 1];
            res += mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];
            
            ans = max(ans, res)
        }
    }
    fmt.Println(ans);
}
