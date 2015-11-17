package main

import (
    "fmt"
    "sort"
    "bufio"
    "os"
)

func min(a int, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}

func main() {
    cin := bufio.NewReader(os.Stdin)
    n := 0
    var ns []int

    fmt.Fscanf(cin, "%d\n", &n)
    for i := 0; i < n; i++ {
        x := 0
        fmt.Fscanf(cin, "%d\n", &x)
        ns = append(ns, x)
    }

    sort.Ints(ns)

    ans := 0x3f3f3f3f
    for i := 0; i + n / 2 < n; i++ {
        a := ns[i]
        b := ns[i + n / 2]
        ans = min(ans, b - a)
    }

    fmt.Println(ans)
}
