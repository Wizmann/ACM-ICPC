package main
import (
    "fmt"
    "strconv"
)

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func main() {
    var n int64
    fmt.Scanf("%d", &n)
    s := strconv.FormatInt(n, 2)
    
    ans := 0
    pre := 0
    tot := 0
    l := len(s)
    for i := 0; i <= l; i++ {
        cur := 0
        if i < l {
            cur = int(s[i]) - '0'
        } else {
            cur = 0
        }
        
        if pre == 1 && cur == 1 {
            tot += 1
        } else {
            ans = max(ans, tot)
            tot = 1
        }
        
        pre = cur
    }
    fmt.Println(ans)
}
