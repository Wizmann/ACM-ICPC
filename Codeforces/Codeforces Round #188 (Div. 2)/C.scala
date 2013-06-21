//Result:3909622     Jun 17, 2013 4:30:07 PM    Wizmann  C - Perfect Pair    Scala  Accepted     328 ms  100 KB
import scala.annotation.tailrec
object C {
    @tailrec
    def solve(x: Long, y: Long, m: Long, res: Long = 0): Long = {
        if(x >= m || y >= m) res
        else if(x <= y) {
            val t = (y - x + y) / y
            solve(y, x + y * t, m, res + t)
        }
        else solve(y, x, m, res)
    }
    def main(args: Array[String]) {
        val Array(x, y, m) = readLine.split(" ").map(_.toLong)
        if(x < m && y < m && (x <= 0 && y <= 0)) println(-1)
        else println(solve(x, y, m))
    }
}