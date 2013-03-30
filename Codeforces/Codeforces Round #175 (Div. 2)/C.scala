import scala.annotation.tailrec
import scala.math._
object C
{
    def main(args: Array[String])
    {
        val n = readLine.toInt
        val a = readLine split(" ") map(_ toInt) sortWith(_ < _)
        @tailrec
        def solve(pos : Int = 0, ans : Long = 0): Long = {
            if(pos<a.length){
                solve(pos+1,ans+abs(a(pos)-(pos+1)))
            }
            else{ans}
        }
        println(solve())
    }
}

