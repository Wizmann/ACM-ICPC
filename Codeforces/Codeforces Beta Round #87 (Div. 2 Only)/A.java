import java.util.*;
import java.math.*;
import java.io.*;
 
 
public class Pro_A
{
	public static void main(String args[])
	{
		Scanner scanner= new Scanner(System.in);
		int n = scanner.nextInt();
		int ans=0;
		int on=0;
		for(int i=0;i<n;i++)
		{
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			on -= a;
			on += b;
			ans = Math.max(ans,on);
		}
		System.out.println(ans);
	}
}
