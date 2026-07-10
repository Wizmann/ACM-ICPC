use std::io::{self, Read};

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

    let a: i32 = sc.next();
    let b: i32 = sc.next();

    if a * 3 > b * 2 {
        println!("Yes");
    } else {
        println!("No")
    }
}

/*
^^^^TEST^^^^^
316 465
---------
Yes
$$$$TEST$$$$

^^^^TEST^^^^^
101 248
---------
No
$$$$TEST$$$$

^^^^TEST^^^^^
666 999
---------
No
$$$$TEST$$$$
*/
