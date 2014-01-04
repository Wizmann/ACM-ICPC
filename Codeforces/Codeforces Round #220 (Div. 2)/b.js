var SIZE = 100100;

function main() {
    var line = "9" + readline() + "9";
    line = line.split('').map(function(item) {
        return parseInt(item, 10);
    });
    
    var res = 1;
    var cnt = 1;
    for (var i = 1; i < line.length; i++) {
        // print(line[i-1], line[i]);
        if (line[i-1] + line[i] == 9) {
            cnt += 1
        } else {
            if (cnt > 1 && cnt % 2 == 1) res *= Math.floor(cnt/2) + 1;
            cnt = 1;
        }  
        // print(cnt);
    }
    print(res);
}

main();
