using System;
using System.Collections.Generic;
using System.Linq;

public class Kata
{
    public static bool ValidateWord(string s)
    {
        var d = new Dictionary<char, int>();
        foreach (var c in s.ToLower()) {
            if (!d.ContainsKey(c)) {
                d[c] = 0;
            }
            d[c] += 1;
        }
        int pre = -1;
        foreach (var p in d) {
            if (pre == -1) {
                pre = p.Value;
            } else {
                if (pre != p.Value) {
                    return false;
                }
            }
        }
        return true;
    }
}
