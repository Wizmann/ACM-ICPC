using System;
using System.Globalization;
using System.Linq;
using System.Numerics;

class Solution {

    static void Main(String[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] arr_temp = Console.ReadLine().Split(' ');
        var arr = Array.ConvertAll(arr_temp,BigInteger.Parse);

        var sum = arr.Aggregate(BigInteger.Zero, (current, num) => BigInteger.Add(current, num));
        Console.WriteLine(sum);
    }
}

