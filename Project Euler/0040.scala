object PE {
    def main(args: Array[String]) {
        println((1 to 1000).map(getDigit(_, 1)).mkString(""))
        val req = Array(1, 10, 100, 1000, 10000, 100000, 1000000)
        println(req.map(getDigit(_, 1)).reduce(_ * _))
    }
    def getDigit(x: Int, digit: Int): Long = {
        val num = Math.pow(10, digit - 1).toInt * 9 * digit
        if (x > num) {
            val y = x - num
            getDigit(y, digit + 1)
        } else {
            val u = x / digit
            val v = x % digit
            if (v == 0) {
                _getDigit(Math.pow(10, digit - 1).toInt + u - 1, digit - 1)
            } else {
                _getDigit(Math.pow(10, digit - 1).toInt + u, v - 1)
            }
        }
    }

    def _getDigit(x: Int, digit: Int): Long = {
        x.toString.charAt(digit) - '0'
    }
}