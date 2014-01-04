object PE_1 {
    def main(args: Array[String]) {
        println((0 until 1000).filter(x => x % 3 == 0 || x % 5 == 0).sum)
    }
}