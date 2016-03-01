using System;
using System.Linq;

public class Kata
{
  public static int [] getLargerNumbers(int [] a , int [] b)
  {
      return a.Zip(b, (_a, _b) => Math.Max(_a, _b)).ToArray();
  }
}
