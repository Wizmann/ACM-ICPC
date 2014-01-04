object Main {
    def main(args: Array[String]) {
        val n = readInt
        val A = readLine.split(" ")
                        .map(_.toLong)
                        .zipWithIndex
                        .sortBy(_._1)
                        .toList

        val B = Array.ofDim[Long](n)
        solve(A, B, 0)
        println(B.mkString(" "))
    }

    def solve(A: List[(Long, Int)], B: Array[Long], maxi: Long) {
        A match {
            case x::xs => {
                val res = Math.max(maxi, x._1)
                val pos = x._2
                B(pos) = res
                solve(xs, B, res + 1)
            }
            case Nil => Nil
        }
    }
}