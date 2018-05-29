package main

import (
    "fmt"
    "sort"
)

func main() {
    var n int
    fmt.Scan(&n)

    var ns = make([]int, n)
    for i := range ns {
        fmt.Scan(&ns[i])
    }

    sort.Ints(ns)

    if len(ns) % 2 == 0 {
        fmt.Println(ns[len(ns) / 2 - 1])
    } else {
        fmt.Println(ns[len(ns) / 2])
    }
}
