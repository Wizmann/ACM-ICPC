import scala.annotation.tailrec;
object PE_2 {
    def main(args: Array[String]) {
        println(fib_sum(0, 1, 0));
    }

    @tailrec
    def fib_sum(a: Long, b: Long, sum: Long): Long = {
        val c = a + b
        println(a, b, c)
        if (c > 4000000) {
            sum
        } else {
            if (c % 2 == 0) {
                fib_sum(b, c, sum + c)
            } else {
                fib_sum(b, c, sum)
            }
        }
    }
}