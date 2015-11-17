package main

import (
    "os"
    "fmt"
    "bufio"
)

func main() {
    n := 0
    k := 0
    cin := bufio.NewReader(os.Stdin)
    fmt.Fscanf(cin, "%d %d\n", &n, &k)
    
    var As [100000]int64
    var Bs [100000]int64

    for i := 0; i < n / k; i++ {
        fmt.Fscanf(cin, "%d", &As[i])
    }
    fmt.Fscanf(cin, "\n")
    for i := 0; i < n / k; i++ {
        fmt.Fscanf(cin, "%d", &Bs[i])
    }
    fmt.Fscanf(cin, "\n")

    const MOD = 1000000000 + 7
    var ans int64
    ans = 1

    var tens [12]int64
    tens[0] = 1

    for i := 1; i < 12; i++ {
        tens[i] = (tens[i - 1] * 10) % MOD
    }

    for i := 0; i < n / k; i++ {
        var l, r, c int64
        l = Bs[i] * tens[k - 1]
        r = Bs[i] * tens[k - 1]+ tens[k - 1] - 1
        c = tens[k] - 1

        cur := c / As[i] - r / As[i] + l / As[i]
        if l != 0 && l % As[i] == 0 {
            cur--
        }
        if Bs[i] != 0 {
            cur++
        }
        fmt.Println(l, r, c, As[i], cur)
        ans = (ans * cur) % MOD
        if ans == 0 {
            break
        }
    }
    fmt.Println(ans)
}
