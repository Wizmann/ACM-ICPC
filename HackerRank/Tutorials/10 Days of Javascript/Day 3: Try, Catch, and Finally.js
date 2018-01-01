/*
 * Complete the reverseString function
 * Use console.log() to print to stdout.
 */
function reverseString(s) {
    try {
        var ss = s.split('').reverse().join('');
        console.log(ss);
    } catch (e) {
        console.log(e.message);
        console.log(s);
    }
}
