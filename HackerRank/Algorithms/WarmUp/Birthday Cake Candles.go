package main
import "fmt"

func main() {
    n := 0
    fmt.Scanf("%d", &n)
    
    var ns []int
    for i := 0; i < n; i++ {
        x := 0
        fmt.Scanf("%d", &x)
        ns = append(ns, x)
    }
    
    maxi := ns[0]
    for i := 0; i < n; i++ {
        if ns[i] > maxi {
            maxi = ns[i]
        }
    }

    ans := 0
    for i := 0; i < n; i++ {
        if ns[i] == maxi {
            ans += 1
        }
    }
    
    
    fmt.Println(ans)
}