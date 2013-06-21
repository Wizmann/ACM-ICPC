//Result:3771310     May 26, 2013 3:34:31 PM    Wizmann  B - Continued Fractions     Scala  Accepted    343 ms  108 KB
import scala.annotation.tailrec
object B {
    def main(args: Array[String]) {
        val pp = readLine.split(" ").map(_.toLong).toList
        val p = pp(0)
        val q = pp(1)
        val n = readInt
        val aa = readLine.split(" ").map(_.toLong).toList

        @tailrec
        def gcd(x: Long, y:Long): Long = {
            if( x < y ) gcd(y,x)
            else if( x % y == 0 ) y
            else gcd(y, x%y)
        }

        @tailrec
        def calc(l: List[Long], x: BigInt, y: BigInt): (BigInt, BigInt) = {
            //println((x,y))
            l match {
                case Nil => {
                    val t = x.gcd(y)
                    ( x / t, y / t)
                }
                case _ => {
                    val next = l.last
                    val nx = ( y * next ) + x
                    val ny = y
                    val t = nx.gcd(ny).toLong
                    calc(l.init, ny/t, nx/t)
                }
            }
        }

        val (a, b) = calc(aa.init, 1, aa.last)
        val t = gcd(p, q)
        val np = p/t
        val nq = q/t
        //println(a, b)
        //println(np, nq)
        if( a == nq && b == np) println("YES")
        else println("NO")
    }
}