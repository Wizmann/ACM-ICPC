object PE {
    def main(args: Array[String]) {
        var ans = 0
        var p = -1
        for (i <- (1 to 1000)) {
            val v = judge(i);
            println(i + " >> " + v)
            if (v > ans) {
                ans = v
                p = i
            }
        }
        println(p + " >> " + ans)
    }

    def judge(n: Int): Int = {
        var res = 0
        for (i <- (1 to n)) {
            for (j <- (i + 1 to n)) {
                val k = n - i - j
                if (k > j && i * i + j * j == k * k) {
                    res += 1
                }
            }
        }

        res
    }
}