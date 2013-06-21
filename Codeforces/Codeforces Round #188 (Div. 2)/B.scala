import scala.annotation.tailrec
object B {
    def getSlice(s: String, h: String, idx: Int = 0, res: List[Int] = Nil): List[Int] = {
        s.indexOf(h, idx) match {
            case -1 => res
            case x => getSlice(s, h, x + h.length, x :: res)
        }
    }

    @tailrec
    def solve(l: List[Int], r: List[Int], llen: Long, rlen: Long, res: Long = 0): Long = {
        l match {
            case x :: xs => {
                r match {
                    case y :: ys => {
                        if(x > y) solve(l, ys, llen, rlen-1, res)
                        else solve(xs, r, llen-1, rlen, res + rlen)
                    } 
                    case Nil => res
                }
            }
            case Nil => res
        }
    }

    def main(args: Array[String]) {
        val ll = readLine
        val heavy = getSlice(ll, "heavy").sortWith(_ < _)
        val metal = getSlice(ll, "metal").sortWith(_ < _)
        println(solve(heavy, metal, heavy.length, metal.length))
    }
}