use std::io::{self, Read};
use std::cmp::{max, min};

struct Scanner {
    input: Vec<String>,
}

impl Scanner {
    fn new() -> Self {
        let mut input = String::new();
        io::stdin().read_to_string(&mut input).unwrap();
        let input = input
            .split_whitespace()
            .rev()
            .map(String::from)
            .collect();

        Self { input }
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        self.input.pop().unwrap().parse().ok().unwrap()
    }
}

fn main() {
    let mut sc = Scanner::new();

    let x: i32 = sc.next();
    let y: i32 = sc.next();
    let l: i32 = sc.next();
    let r: i32 = sc.next();
    let a: i32 = sc.next();
    let b: i32 = sc.next();

    let st = max(a, l);
    let end = min(r, b);
    if (st < end) {
        let u1 = end - st;
        let u2 = (b - a) - u1;
        println!("{}", u1 * x + u2 * y);
    } else {
        println!("{}", (b - a) * y);
    }
}

/*
^^^^TEST^^^^
700 300 9 17 7 21
--------
7400
$$$$$TEST$$$$$

^^^^TEST^^^^
600 500 9 17 17 20
--------
1500
$$$$$TEST$$$$$

^^^^TEST^^^^
900 200 12 14 11 13
--------
1100
$$$$$TEST$$$$$

^^^^TEST^^^^
100 10 5 15 7 10
--------
300
$$$$$TEST$$$$$

^^^^TEST^^^^
100 10 5 15 1 4
--------
30
$$$$$TEST$$$$$

^^^^TEST^^^^
100 10 5 15 15 18
--------
30
$$$$$TEST$$$$$
*/
