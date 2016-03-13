using System;
using System.Linq;

class Untitled
{
	static void Main(string[] args)
	{
		int n = Int32.Parse(Console.ReadLine());
		var nums = Console.ReadLine()
		                  .Split(' ')
						  .Select(x => Int32.Parse(x))
						  .ToArray();
		long ans = 1;
		long cnt = 0;
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) {
				cnt++;
			} else {
				if (!flag) {
					flag = true;
					cnt = 0;
				} else {
					ans *= (cnt + 1);
					cnt = 0;
				}
			}
		}
		if (flag) {
			Console.WriteLine(ans);
		} else {
			Console.WriteLine(0);
		}
	}
}