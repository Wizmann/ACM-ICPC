function main() {
    const PI = 3.141592653589793;
    
    var r = parseFloat(readLine())
    
    console.log(PI * r * r);
    console.log(PI * r * 2);
    
    try {    
        // Attempt to redefine the value of constant variable PI
        PI = 0;
        // Attempt to print the value of PI
        console.log(PI);
    } catch(error) {
        console.error("You correctly declared 'PI' as a constant.");
    }
}
