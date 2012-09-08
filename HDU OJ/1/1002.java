//Result:2012-09-08 10:57:20	Accepted	1002	156MS	3440K	466 B	Java	Wizmann
import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String args[]) throws IOException
	{
		int cas=1,T;
		Scanner cin=new Scanner(System.in);
		T=cin.nextInt();
		while((T--)>0)
		{
			BigInteger a=cin.nextBigInteger();
			BigInteger b=cin.nextBigInteger();
			System.out.println("Case "+cas+++":");
			System.out.println(a+" + "+b+" = "+a.add(b));
			if(T>0) System.out.println("");
		}
	}
}
