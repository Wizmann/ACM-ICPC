using System;

public class Solution {
    public static void printArray<T>(System.Collections.Generic.IEnumerable<T> enumerable) {
        foreach (var item in enumerable) {
            Console.WriteLine(item);
        }
    }
    static void Main(string[] args) {
       int[] vInt = new int[] {1, 2, 3};
       string[] vString = new string[] {"Hello", "World"};
       
       printArray<int>(vInt);
       printArray<string>(vString);
    }
}
