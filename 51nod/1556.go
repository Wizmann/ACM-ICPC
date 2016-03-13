package main

import "fmt"


func Pow(a int64, b int64, mod int64) int64 {
    var p int64 = 1
    for b > 0 {
        if b&1 != 0 {
            p = (p * a) % mod
        }
        b >>= 1
        a = (a * a) % mod
     }
     return p
}


func main() {
    var MOD int64 = 1000000000 + 7
    var m[1000011] int32
    
    var n int64 = 0
    fmt.Scanf("%d", &n)
    
    if n <= 2 {
        fmt.Print(n)
    }
    
    m[0] = 1
    m[1] = 1
    m[2] = 2

    var i int64 = 2
    var a int64 = 1
    var b int64 = 2
    var c int64 = 0
    for i <= n {
        x := (2 * i + 3) * b % MOD
        y := 3 * i * a % MOD
        z := (x + y) % MOD
        c = (z * Pow(i + 3, MOD - 2, MOD)) % MOD
        
        m[i + 1] = int32(c)
        a = b
        b = c
        i += 1
    }
    
    res := Pow(3, n - 1, MOD)
    i = 0
    for i < n - 1 {
        a = int64(m[i])
        b = Pow(3, n - i - 2, MOD)
        c = a * b % MOD
        res = ((res - c) % MOD + MOD) % MOD
        i += 1
    }
    fmt.Print(res)
}