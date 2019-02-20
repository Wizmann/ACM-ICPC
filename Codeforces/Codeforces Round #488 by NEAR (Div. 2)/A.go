package main

import "fmt"

func main() {
    n := 0
    m := 0

    fmt.Scanf("%d%d\n", &n, &m)

    ns := make([]int, n)
    ms := make([]int, 10)

    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &ns[i])
    }
    fmt.Scanf("\n")

    for i := 0; i < m; i++ {
        x := 0
        fmt.Scanf("%d", &x)
        ms[x] = 1
    }
    fmt.Scanf("\n")

    for i := 0; i < n; i++ {
        if (ms[ns[i]] != 0) {
            fmt.Printf("%d ", ns[i])
        }
    }
    fmt.Println("")
}

