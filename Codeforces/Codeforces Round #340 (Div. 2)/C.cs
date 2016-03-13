using System;
using System.Linq;



class Untitled
{
	public class Point {
		public int x;
		public int y;
		
		public Point() {
			// pass
		}
		public Point(int _x, int _y) {
			x = _x;
			y = _y;
		}
	}
	
	static long point_dis_square(Point p1, Point p2) {
		long a = (p1.x - p2.x);
		long b = (p1.y - p2.y);
		return a * a + b * b;
	}
	
	
	static void Main(string[] args)
	{
		var params_ = Console.ReadLine()
							.Split(' ')
							.Select(Int32.Parse)
							.ToArray();
		int n = params_[0];
		Point p1 = new Point(params_[1], params_[2]);
		Point p2 = new Point(params_[3], params_[4]);
		
		Point[] points = new Point[n];
		
		for (int i = 0; i < n; i++) {
			var coordinate = Console.ReadLine()
			                        .Split(' ')
			                        .Select(Int32.Parse)
			                        .ToArray();
			points[i] = new Point(coordinate[0], coordinate[1]);
		}
		
		long ans = Int64.MaxValue;
		for (int i = 0; i <= n; i++) {
			long dis1 = i < n? point_dis_square(p1, points[i]): 0;
			long dis2 = 0;
			for (int j = 0; j < n; j++) {
				long dis1_ = point_dis_square(p1, points[j]);
				
				if (dis1_ <= dis1) {
					continue;
				}
				
				long dis2_ = point_dis_square(p2, points[j]);
				
				dis2 = Math.Max(dis2, dis2_);
			}
			ans = Math.Min(ans, dis1 + dis2);
		}
		Console.WriteLine(ans);
	}
}