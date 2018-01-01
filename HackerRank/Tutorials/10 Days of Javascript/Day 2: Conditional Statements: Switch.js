function getLetter(s) {
    if ("aeiou".indexOf(s[0]) != -1) {
        return "A";
    } else if ("bcdfg".indexOf(s[0]) != -1) {
        return "B";
    } else if ("hjklm".indexOf(s[0]) != -1) {
        return "C";
    } else {
        return "D";
    }
}
