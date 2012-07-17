//Result:2012-07-16 16:43:00	Accepted	2500	187MS	2668K	457 B	Java	Wizmann
import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static final String hdu="HDU";
	public static Scanner cin = new Scanner(System.in);
	public static void main(String args[])
	{
		int T=cin.nextInt();
		for(int cas=0;cas<T;cas++)
		{
			int n=cin.nextInt();
			for(int i=0;i<n*3;i++)
			{
				for(int j=0;j<n;j++)
				{
					System.out.print(hdu);
				}
				System.out.println("");
			}
		}
	}
}
