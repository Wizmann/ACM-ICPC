using System;
using System.Linq;

class Untitled
{
	static void Main(string[] args)
	{
		int n = Int32.Parse(Console.ReadLine());
		
		var mat0 = new int[n, n];
		var mat1 = new int[n, n];
		
		for (int i = 0; i < n; i++) {
			var row = Console.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
			for (int j = 0; j < n; j++) {
				mat0[i, j] = row[j];
			}
		}
		
		for (int i = 0; i < n; i++) {
			var row = Console.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
			for (int j = 0; j < n; j++) {
				mat1[i, j] = row[j];
			}
		}
		
		var mat2 = new int[n, n];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					mat2[i, j] += mat0[i, k] * mat1[k, j];
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Console.Write("{0} ", mat2[i, j]);
			}
			Console.WriteLine();
		}
	}
}