//Result:3909085     Jun 17, 2013 2:01:38 PM    Wizmann  A - Even Odds   Scala  Accepted     312 ms  100 KB
object A {
    def main(args: Array[String]) {
        val Array(n, k) = readLine.split(" ").map(_.toLong)
        val ans = k match {
            case x if x <= (n + 1) / 2 => x * 2 - 1
            case x => (x - (n + 1) / 2 ) * 2
        }
        println(ans)
    }
}