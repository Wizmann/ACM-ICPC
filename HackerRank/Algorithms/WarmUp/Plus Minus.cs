using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution {
    static void Main(String[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] arr_temp = Console.ReadLine().Split(' ');
        int[] arr = Array.ConvertAll(arr_temp,Int32.Parse);
        int a = arr.Where(x => x > 0).ToList().Count;
        int b = arr.Where(x => x < 0).ToList().Count;
        int c = n - a - b;
        Console.WriteLine(1.0 * a / n);
        Console.WriteLine(1.0 * b / n);
        Console.WriteLine(1.0 * c / n);
    }
}
