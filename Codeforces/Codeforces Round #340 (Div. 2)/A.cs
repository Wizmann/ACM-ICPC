using System;

namespace CodeRunner
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			Console.Write((int)(n + 4) / 5);
		}
	}
}