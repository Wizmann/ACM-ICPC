using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Globalization;
using System.Collections.Generic;

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

    class Program
    {
        static bool isLeapYear(int x)
        {
            if (x%100 == 0)
            {
                return x%400 == 0;
            }
            else
            {
                return x%4 == 0;
            }
        }
        static void Main(string[] args)
        {
            int a = Cin.NextInt();
            int b = a / 4000 * 4000;
            a %= 4000;
            
            for (int i = a + 1; /* pass */; i++)
            {
                var d1 = DateTime.Parse(string.Format("{0}-01-01", a));
                var d2 = DateTime.Parse(string.Format("{0}-01-01", i));
                
                var diff = d2 - d1;
                bool ly = !(isLeapYear(a) ^ isLeapYear(i));
                bool wd = diff.Days%7 == 0;

                if (ly && wd)
                {
                    Console.WriteLine(i + b);
                    break;
                }
            }
        }
    }
}
