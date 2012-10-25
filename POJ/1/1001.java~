//Result:wizmann	1001	Accepted	3896K	235MS	Java	642B
import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin=new Scanner(System.in);
		BigDecimal num;
		int mulPow;
		while(cin.hasNext())
		{
			num=cin.nextBigDecimal();
			mulPow=cin.nextInt();
			num=num.pow(mulPow);
			
			String output=num.toPlainString();
			int st=0,end=output.length()-1;
			while(output.charAt(st)=='0') st++;
			while(output.charAt(end)=='0') end--;
			if(output.charAt(end)=='.') end--;
			
			while(st<=end) System.out.printf("%c",output.charAt(st++));
			System.out.println();
		}
	}
}
