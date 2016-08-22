import java.io.*;
import java.util.*;
import java.math.*;

public class Main 
{
	public static BigInteger min(BigInteger a,BigInteger b)
	{
		if(a.compareTo(BigInteger.valueOf(-1))==0) return b;
		else if(b.compareTo(BigInteger.valueOf(-1))==0) return a;
		else
		{
			if(a.compareTo(b)<0) return a;
			else return b;
		}
	}

	public static void main(String args[]) throws IOException
	{
		Scanner cin = new Scanner(System.in);
		
		//重定向
		Scanner cin = new Scanner(new File("input.txt"));
		
		//读入
		cin.nextInt();
		cin.nextBigInteger();
		
		//赋值
		BigInteger zehn=BigInteger.valueOf(10);
		
		//数学运算
		BigInteger tmp=p.add(BigInteger.valueOf(b));
		BigInteger tmp=p.subtract(BigInteger.valueOf(b));
		BigInteger tmp=p.multiply(BigInteger.valueOf(b));
		BigInteger tmp=p.divide(BigInteger.valueOf(b));
		BigInteger tmp=p.mod(BigInteger.valueOf(b));
		BigInteger tmp=p.pow(b);//BigInteger.pow(int)
		
		//数字转字符串
		String atxt=BigInteger.toString();
		String btxt=String.valueOf(int);
		int len=atxt.length();
		
		//字符串查找
		int pos=atxt.indexOf(btxt);
		
		//比较大小
		a.compareTo(BigInteger.valueOf(b))<0
}

