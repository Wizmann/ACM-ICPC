use std::io::{self, Read};
use std::collections::VecDeque;

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

fn solve(n: i32, s: &[u8]) -> VecDeque<usize> {
    if (n == -1) {
        return VecDeque::new();
    }
    if (s[n as usize] == b'o') {
        let mut result = solve(n - 1, s);
        result.make_contiguous().reverse();
        result.push_front((n + 1) as usize);
        return result;
    } else {
        let mut result = solve(n - 1, s);
        result.push_back((n + 1) as usize);
        return result;
    }
}

fn main() {
    let mut sc = Scanner::new();
    let n: i32 = sc.next();
    let s: String = sc.next();

    let res = solve(n - 1, s.as_bytes());
    println!("{}", res.iter().map(|x| x.to_string()).collect::<Vec<_>>().join(" "));

}

/*
^^^^TEST^^^^
5
ooxoo
--------
5 2 1 3 4
$$$$TEST$$$$$

^^^^^TEST^^^^
7
ooooooo
----------
7 5 3 1 2 4 6
$$$$TEST$$$$

^^^^^TEST^^^^
15
xooxoxoxoxoxxoo
----------
15 11 10 7 6 3 1 2 4 5 8 9 12 13 14
$$$$TEST$$$$
*/
