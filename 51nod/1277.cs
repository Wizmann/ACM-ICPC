using System;
using System.IO;

class Untitled
{
	static int[] get_next(string str) {
		int n = str.Length;
		int[] next = new int[n + 1];
		
		next[0] = -1;
		
		for (int pre = -1, suf = 0; suf < n; /* pass */) {
			if (pre == -1 || str[pre] == str[suf]) {
				pre++;
				suf++;
				next[suf] = pre;
			} else {
				pre = next[pre];
			}
		}
		
		return next;
	}
	static void Main(string[] args)
	{
		var str = Console.ReadLine();
		var next = get_next(str);
		
		long ans = 0;
		int n = str.Length;
		long[] dp = new long[n + 1];
		
		for (int i = 0; i <= n; i++) {
			dp[i] = 1;
		}
		
		for (int i = n; i > 0; i--) {
			int p = next[i];
			dp[p] += dp[i];
		}
		
		for (int i = 1; i <= n; i++) {
			ans = Math.Max(ans, dp[i] * i);
		}
		Console.WriteLine(ans);
	}
}