using System;
using System.Collections.Generic;
using System.IO;

class Solution {
    private static List<int> fibs = new List<int>();
    static Solution() {
        fibs.Add(0);
        fibs.Add(1);
        for (int i = 2; i <= 42; i++) {
            fibs.Add(fibs[i - 1] + fibs[i - 2]);
        }
    }
    public static int Fibonacci(int n) {
        return fibs[n];
    }

    static void Main(String[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine(Fibonacci(n));
    }
}

