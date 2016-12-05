package main
import (
    "fmt"
)

func max(x, y int) int {
    if (x > y) {
        return x
    } else {
        return y
    }
}

func main() {
    const N = 26
    var ns [N]int
    for i := 0; i < N; i++ {
        fmt.Scanf("%d", &ns[i])
    }
    var s string
    fmt.Scanf("%s", &s)
    
    maxi := 0
    for _, c := range s {
        maxi = max(maxi, ns[c - 'a'])
    }
    
    fmt.Println(maxi * len(s))
    
}
