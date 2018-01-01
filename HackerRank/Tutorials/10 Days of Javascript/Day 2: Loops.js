/*
 * Complete the vowelsAndConsonants function.
 * Print your output using 'console.log()'.
 */
function vowelsAndConsonants(s) {
    s = s.split('');

    var n = s.length;
    var l = []
    var r = [];
    
    for (var i = 0; i < n; i++) {
        if ("aeiou".indexOf(s[i]) != -1) {
            l = l.concat(s[i]);
        } else {
            r = r.concat(s[i]);
        }
    }
    
    console.log(l.join("\n"));
    console.log(r.join("\n"));
}
