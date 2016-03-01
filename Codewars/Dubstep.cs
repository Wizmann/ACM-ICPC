using System;
using System.Linq;

public class Dubstep
{
    public static string SongDecoder(string input)
    {
        const string delim = "WUB";
        var wordlist = input.Split(
            new string[] { delim }, StringSplitOptions.None
        ).Where(x => x.Length != 0);
        return String.Join<string>(" ", wordlist);
    }    
}
