using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Globalization;
using System.Collections.Generic;
using System.Dynamic;

namespace ConsoleApplication1
{
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
        public static long NextLong()
        {
            string token = Cin.NextToken();
            return long.Parse(token);
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

    public static class Cout
    {
        public static void Print<T>(T item)
        {
            Console.WriteLine(item.ToString());
        }
    }

    public static class Solution
    {
        static void Main(String[] args)
        {
            int n = Cin.NextInt();
            int k = Cin.NextInt();
            int q = Cin.NextInt();
            
            int[] ns = new int[n];
            for (int i = 0; i < n; i++) {
                ns[i] = Cin.NextInt();
            }
            
            k %= n;
            var res = ns;
            if (k != 0) {
                var l = ns.ToList().GetRange(0, n - k).ToArray();
                var r = ns.ToList().GetRange(n - k, k).ToArray();
                res = r.Concat(l).ToArray();
            }

            for (int i = 0; i < q; i++) {
                int Q = Cin.NextInt();
                Cout.Print(res[Q]);
            }
        }
    }
}
