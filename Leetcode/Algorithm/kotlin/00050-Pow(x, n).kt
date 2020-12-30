class Solution {
    fun myPow(x: Double, n: Int): Double {
        return myPow_(x, n.toLong())
    }
        
    fun myPow_(x: Double, n: Long): Double {
        if (n == 0L) {
            return 1.0
        }
        if (n < 0L) {
            return 1.0 / myPow_(x, -n)
        }
        assert(n > 0);
        
        var res: Double = 1.0
        var xx = x
        var nn = n
        while (nn > 0) {
            // println("${nn}, ${xx}")
            if ((nn and 1L) != 0L) {
                res *= xx
            }
            xx = xx * xx
            nn = nn shr 1
        }
        return res
    }
}
