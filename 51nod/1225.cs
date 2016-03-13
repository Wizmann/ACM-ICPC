using System;

class Untitled
{
	const int MOD = 1000000007;
	const int MAGIC = 500000004;
	
	static long solve(long n) {
		long p = n;
		long ans = 0;
		while (p != 0) {
			long x = n / p;
			long a = n / (x + 1) + 1;
			long b = p;
			
			long v0 = (n % a + n % b) % MOD;
			long v1 = (b - a + 1) % MOD;
			long v2 = v0 * v1 % MOD;
			long v3 = v2 * MAGIC % MOD;
			ans = (ans + v3) % MOD;
	
			p = a - 1;
		}
		return ans;
	}
	
	static void Main(string[] args)
	{
		var n = Int64.Parse(Console.ReadLine());
		
		Console.WriteLine(solve(n) % MOD);
	}
}