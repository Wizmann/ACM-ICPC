function main() {
    var line = readline().split(' ')
    var a = parseInt(line[0])
    var b = parseInt(line[1])

    var res = solve(a, 0, b, 0)
    print(res);
}

function solve(newc, usedc, b, res) {
    // print(newc, usedc, b, res)
    res += newc
    usedc += newc;
    newc = Math.floor(usedc / b)
    usedc %= b;

    if (newc == 0) {
        return res;
    } else {
        return solve(newc, usedc, b, res);
    }
}

main()
