using System;

public class Kata
{
  public static string BuildRowText(int index, char character)
  {
  	const int LENGTH = 19;
  	char[] res = new char[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
    	res[i] = i % 2 != 0? ' ': '|';
    }
    res[index * 2 + 1] = character;
    return new string(res);
  }
}
