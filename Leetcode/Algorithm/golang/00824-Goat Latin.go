import (
    "fmt"
    "strings"
)

func wordToLatin(word string, idx int) string {
    if strings.Contains("aeiouAEIOU", string(word[0])) {
        word += "ma";
    } else {
        word = word[1:] + string(word[0]) + "ma";
    }
    
    for i := 0; i <= idx; i++ {
        word += "a";
    }
    return word;
}

func toGoatLatin(S string) string {
    res := "";
    for i, word := range strings.Split(S, " ") {
        if i != 0 {
            res += " ";
        }
        res += wordToLatin(word, i);
    }
    return res;
}