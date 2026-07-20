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
    let n: i32 = sc.next();
    let mut hit = 0;
    let mut count: Vec<i32> = vec![0; 13];
    for i in 1..=6 {
        for j in 1..=6 {
            let k: usize = i + j;
            count[k] += 1
        }
    }
    for _ in 0..n {
        let u: i32 = sc.next();
        hit += count[u as usize];
    }
    println!("{:.4}", hit as f64 / 36.)
}

/*
^^^^TEST^^^^
1
7
--------
0.16666666666666666
$$$$TEST$$$$$

^^^^TEST^^^^
2
2 12
--------
0.05555555555555555
$$$$TEST$$$$$

^^^^TEST^^^^
11
2 3 4 5 6 7 8 9 10 11 12
--------
1.0
$$$$TEST$$$$$
*/
