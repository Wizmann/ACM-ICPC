// https://www.hackerrank.com/challenges/longest-increasing-subsequence-arrays/problem

package main
import "fmt"

const MOD uint64 = 1000000000 + 7;
const N int = 500010;
var fac = make([]uint64, N)
var inv = make([]uint64, N)

func pow(a uint64, b uint64) uint64 {
    var res uint64 = 1
    for (b != 0) {
        if ((b & 1) != 0) {
            res = (res * a) % MOD
        }
        a = (a * a) % MOD
        b >>= 1
    }
    return res
}

func mul(a uint64, b uint64) uint64 {
    var res uint64 = 0
    for (b != 0) {
        if ((b & 1) != 0) {
            res = res + a
        }
        a = a * 2
        b >>= 1
        if a > MOD {
            a -= MOD
        }
        if res > MOD {
            res -= MOD
        }
    }
    return res
}

func C(n int, m int) uint64 {
    return mul(fac[n] * inv[n - m] % MOD, inv[m])
}

func solve(n int, m int) uint64 {
    if m == 1 {
        return 1
    }
    var res uint64 = 0
    var p1 uint64 = pow(uint64(m - 1), uint64(n - m))
    var inv1 uint64 = pow(uint64(m - 1), MOD - 2)
    var p2 uint64 = 1;
    for i := 0; i <= n - m; i++ {
        var u uint64 = C(n - i - 1, m - 1)
        u = mul(mul(u, p1), p2)
        p1 = p1 * inv1 % MOD
        p2 = p2 * uint64(m) % MOD
        res += u
        if res > MOD {
            res -= MOD
        }
    }
    return res
}

func main() {
    T := 0
    fmt.Scanf("%d", &T)
    fac[0] = 1
    inv[0] = 1
    for i := 1; i < N; i++ {
        fac[i] = mul(fac[i - 1], uint64(i))
        inv[i] = pow(fac[i], MOD - 2)
    }
    for case_ := 0; case_ < T; case_++ {
        n := 0
        m := 0
        fmt.Scanf("%d%d", &n, &m)
        fmt.Println(solve(n, m))
    }
}
