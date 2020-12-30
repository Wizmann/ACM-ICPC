func consecutiveNumbersSum(N int) int {
    ans := 0;
    for i := 1; i * i <= N; i++ {
        if (N % i == 0) {
            ans += check(N, i);
            if (i * i != N) {
                ans += check(N, N / i);
            }
        }
    }
    return ans;
}

func check(N, x int) int {
    res := 0;
    u := N / x;
    if (u % 2 == 1 && x - u / 2 > 0 ) {
        res += 1;
    }
    if (x % 2 == 1 && x / 2 >= u) {
        res += 1;
    }
    return res;
}
