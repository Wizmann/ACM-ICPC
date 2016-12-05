package main
import "fmt"

func min(a int64, b int64) int64 {
    if a < b {
        return a
    } else {
        return b
    }
}

func max(a int64, b int64) int64 {
    if a > b {
        return a
    } else {
        return b
    }
}

func main() {
    const INF int64 = 0x3f3f3f3f3f3f3f3f
    var ns []int64

    for true {
        var x int64
        _, err := fmt.Scanf("%d", &x)
        if err != nil {
            break
        }
        ns = append(ns, x)
    }
    
    var sum int64 = 0
    var mini int64 = INF
    var maxi int64 = -INF
    
    for _, item := range ns {
        sum += item
    }
    
    for _, item := range ns {
        v := sum - item
        mini = min(mini, v)
        maxi = max(maxi, v)
    }
    
    fmt.Printf("%d %d\n", mini, maxi)
}
