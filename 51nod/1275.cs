using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Globalization;
using System.Collections.Generic;

public static class Cin
{
    public static string NextToken()
    {
        StringBuilder tokenChars = new StringBuilder();
        bool tokenFinished = false;
        bool skipWhiteSpaceMode = true;
        while (!tokenFinished)
        {
            int nextChar = Console.Read();
            if (nextChar == -1)
            {
                tokenFinished = true;
            }
            else
            {
                char ch = (char)nextChar;
                if (char.IsWhiteSpace(ch))
                {
                    if (!skipWhiteSpaceMode)
                    {
                        tokenFinished = true;
                        if (ch == '\r' && (Environment.NewLine == "\r\n"))
                        {
                            Console.Read();
                        }
                    }
                }
                else
                {
                    skipWhiteSpaceMode = false;
                    tokenChars.Append(ch);
                }
            }
        }
         
        string token = tokenChars.ToString();
        return token;
    }

    public static int NextInt()
    {
        string token = Cin.NextToken();
        return int.Parse(token);
    }

    public static double NextDouble(bool acceptAnyDecimalSeparator = true)
    {
        string token = Cin.NextToken();
        if (acceptAnyDecimalSeparator)
        {
            token = token.Replace(',', '.');
            double result = double.Parse(token, CultureInfo.InvariantCulture);
            return result;
        }
        else
        {
            double result = double.Parse(token);
            return result;
        }
    }

    public static decimal NextDecimal(bool acceptAnyDecimalSeparator = true)
    {
        string token = Cin.NextToken();
        if (acceptAnyDecimalSeparator)
        {
            token = token.Replace(',', '.');
            decimal result = decimal.Parse(token, CultureInfo.InvariantCulture);
            return result;
        }
        else
        {
            decimal result = decimal.Parse(token);
            return result;
        }
    }
}

class Untitled
{
    static void Main(string[] args)
    {
        int n = Cin.NextInt();
        int k = Cin.NextInt();
        
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Cin.NextInt();
        }
        
        LinkedList<int> mini = new LinkedList<int>();
        LinkedList<int> maxi = new LinkedList<int>();
        
        int l = 0;
        int r = 0;
        long ans = 0;
        while (l < n) {
            while (r < n) {
                while (mini.Count() != 0 && nums[mini.Last()] >= nums[r]) {
                      mini.RemoveLast();
                }
                mini.AddLast(r);
                while (maxi.Count() != 0 && nums[maxi.Last()] <= nums[r]) {
                    maxi.RemoveLast();
                }
                maxi.AddLast(r);
                
                if (nums[maxi.First()] - nums[mini.First()] <= k) {
                    r++;
                } else {
                    break;
                }
            }
            
            ans += (r - l);
            if (mini.First() <= l) {
                mini.RemoveFirst();
            }
            if (maxi.First() <= l) {
                maxi.RemoveFirst();
            }
            l++;
        }
        Console.WriteLine(ans);
    }
}
