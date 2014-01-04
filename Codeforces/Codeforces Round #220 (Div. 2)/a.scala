object A {
    def main(args: Array[String]) {
        val Array(n, m, i, j, a, b) = readLine split(" ") map(_.toInt)

        val ans_list = List(solve(n, m, n, m, i, j, a, b),
                            solve(n, m, n, 1, i, j, a, b),
                            solve(n, m, 1, m, i, j, a, b),
                            solve(n, m, 1, 1, i, j, a, b))
        // println(ans_list.mkString(" "))
        val ans = ans_list.min

        println(if(ans == INF) "Poor Inna and pony!" else ans)
    }

    def solve(n: Int, m: Int, dest_y: Int, dest_x: Int, y: Int, x: Int, a: Int, b: Int): Int = {
        val delta_y = math.abs(dest_y - y)
        val delta_x = math.abs(dest_x - x)

        val step_y = if(delta_y % a == 0 && List(n - y, y - 1).max >= a) delta_y / a else -1
        val step_x = if(delta_x % b == 0 && List(m - x, x - 1).max >= b) delta_x / b else -1

        if (dest_y == y && dest_x == x) {
            0
        } else if (step_x != -1 && step_y != -1 && math.abs(step_y - step_x) % 2 == 0) {
            List(step_x, step_y).max
        } else {
            INF
        }
    }

    val INF = 0x3f3f3f3f;
}