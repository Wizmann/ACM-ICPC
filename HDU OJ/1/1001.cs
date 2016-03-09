// Result: 2016-02-13 13:12:11	Accepted	1001	124MS	12276K	2082 B	C#	Wizmann
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
		return Int32.Parse(token);
	}
	
	public static long NextLong() {
		string token = Cin.NextToken();
		return Int64.Parse(token);
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
		while (true) {
			try {
				decimal x = Cin.NextDecimal();
				Console.WriteLine( (1 + x) * x / 2 );
				Console.WriteLine();
			} catch {
				break;
			}
		}
	}
}