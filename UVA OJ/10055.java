//Result:10055	Hashmat the Brave Warrior	Accepted	JAVA	2.172	2013-03-15 15:21:57
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            long a = cin.nextLong();
            long b = cin.nextLong();
            System.out.println(Math.abs(b-a));
        }
    }
}
