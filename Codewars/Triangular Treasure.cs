using System;

public class Kata
{
    public static int Triangular(int n)
    {
        if (n < 0)
            return 0;
            
        return ((1 + n) * n) / 2;
    }
}
