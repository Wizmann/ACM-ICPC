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
            string[] tokens_n = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(tokens_n[0]);
            int k = Convert.ToInt32(tokens_n[1]);
            string[] a_temp = Console.ReadLine().Split(' ');
            int[] a = Array.ConvertAll(a_temp, Int32.Parse);

            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((a[i] + a[j])%k == 0)
                    {
                        ans++;
                    }
                }
            }
            Cout.Print(ans);
        }
    }
}
